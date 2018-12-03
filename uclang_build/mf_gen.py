#!/usr/bin/python
#VERSION #4

import sys,os
import re
import json

from mf_cfg import *

# - CLASS configuration_c -
class configuration_c:
  C_SHELL_TYPE_WINDOWS  = 0
  C_SHELL_TYPE_BASH     = 1

  C_COMPILER_GCC   = 0
  C_COMPILER_MS_VS = 1

  C_CLEAN_FILE = 0
  C_CLEAN_DIR  = 1

  def __init__(self):
  #{{{

    # Set make directory to actual directory
    self.make_dir = os.getcwd()
    self.test_directory(self.make_dir,True)

    # Set make object directory
    self.object_dir = "object_files"
    object_dir_path = os.path.join(self.make_dir,self.object_dir)
    if not os.path.isdir(object_dir_path):
      os.makedirs(object_dir_path)

    # Set make temporary directory
    self.tmp_dir = "tmp_files"
    tmp_dir_path = os.path.join(self.make_dir,self.tmp_dir)
    if not os.path.isdir(tmp_dir_path):
      os.makedirs(tmp_dir_path)

    # Set make process directory
    self.proc_dir = "proc_files"
    proc_dir_path = os.path.join(self.make_dir,self.proc_dir)
    if not os.path.isdir(proc_dir_path):
      os.makedirs(proc_dir_path)

    # Default definitions
    self.default_cpp_defines = ""

    # Used shell environment
    if os.name == "posix":
      self.shell_type = self.C_SHELL_TYPE_BASH
    elif os.name == "nt":
      self.shell_type = self.C_SHELL_TYPE_WINDOWS
    else:
      assert False

    # Used compiler type
    self.compiler_type = self.C_COMPILER_GCC

    if self.compiler_type == self.C_COMPILER_GCC:

      # Default compiler options
      self.default_cpp_options = "-O2"
      self.default_cpp_link_options = ""

    elif self.compiler_type == self.C_COMPILER_MS_VS:

      # Texas instruments install directory
      self.ms_vs_dir = ""
      self.test_directory(self.ms_vs_dir,False)

      # Default compiler options
      self.default_cpp_options = "/O2"
      self.default_cpp_link_options = ""

    else:
      assert False

    # Initialize set of files to clean
    self.clean_set = set()
  #}}}

  @staticmethod
  def test_file(a_file,a_test_spaces):
  #{{{
    assert a_file.__class__ == str

    if not os.path.isfile(a_file):
      print >> sys.stderr, "Error: File \"%s\" does not exist." % a_file
      sys.exit(1)

    if a_test_spaces:
      if " " in a_file:
        print >> sys.stderr, "Error: File path \"%s\" should not contain spaces." % a_file
        sys.exit(1)
  #}}}

  @staticmethod
  def test_directory(a_dir,a_test_spaces):
  #{{{
    assert a_dir.__class__ == str

    if not os.path.isdir(a_dir):
      print >> sys.stderr, "Error: Directory \"%s\" does not exist." % a_dir
      sys.exit(1)

    if a_test_spaces:
      if " " in a_dir:
        print >> sys.stderr, "Error: Directory path \"%s\" should not contain spaces." % a_dir
        sys.exit(1)
  #}}}

  def str_message(self,a_message):
  #{{{
    assert a_message.__class__ == str

    string = ""

    if self.shell_type == self.C_SHELL_TYPE_WINDOWS:
      string += "\techo %s\n" % a_message
    elif self.shell_type == self.C_SHELL_TYPE_BASH:
      string += "\tprintf \"%s\\n\"\n" % a_message
    else:
      assert False

    return string
  #}}}

  def str_setting(self):
  #{{{
    string = "# --- Configuration setting ---\n"
    string += "\n"

    if self.compiler_type == self.C_COMPILER_MS_VS:
      string += "MS_VS_DIR=%s\n" % self.ms_vs_dir

    string += "MAKE_DIR=%s\n" % self.make_dir
    string += "\n"

    string += "MAKE_OBJECT_DIR=$(MAKE_DIR)%s%s\n" % (os.sep,self.object_dir)
    string += "MAKE_TMP_DIR=$(MAKE_DIR)%s%s\n" % (os.sep,self.tmp_dir)
    string += "MAKE_PROC_DIR=$(MAKE_DIR)%s%s\n" % (os.sep,self.proc_dir)
    string += "\n"

    if self.compiler_type == self.C_COMPILER_GCC:
      #string += "CXX=clang++\n"
      string += "CXX=g++\n"
    elif self.compiler_type == self.C_COMPILER_MS_VS:
      string += "CXX=cl\n"
    else:
      assert False

    if self.shell_type == self.C_SHELL_TYPE_BASH:
      string += "PROC=process\n"
    elif self.shell_type == self.C_SHELL_TYPE_WINDOWS:
      string += "PROC=process\n"
    else:
      assert False

    return string
  #}}}

  def str_all_target(self, a_components):
  #{{{
    string = "# --- Compilation targets ---\n"
    string += "\n"

    string += "all: "

    c_idx = 0
    while c_idx < len(a_components):
      comp = a_components[c_idx]
      string += "%s$(%s_TMP)%s%s \\\n" % ("" if c_idx == 0 else "   ",comp.get_abbr(),os.sep,comp.get_target())
      c_idx += 1

    string += "\n"

    if self.shell_type == self.C_SHELL_TYPE_WINDOWS:
      for comp in a_components:
        string += "\txcopy \"$(%s_TMP)%s%s\" . /y /q > NUL\n" % (comp.get_abbr(),os.sep,comp.get_target())

    elif self.shell_type == self.C_SHELL_TYPE_BASH:
      for comp in a_components:
        string += "\tcp $(%s_TMP)%s%s %s\n" % (comp.get_abbr(),os.sep,comp.get_target(),comp.get_target())

    else:
      assert False

    return string
  #}}}

  def str_process_target(self, a_components):
  #{{{
    string = "# --- Process targets ---\n"
    string += "\n"

    string += "process: "

    c_idx = 0
    while c_idx < len(a_components):
      comp = a_components[c_idx]

      if str(comp.__class__) == "__main__.module_c":
        comp = comp.mod_proj

      s_idx = 0
      while s_idx < len(comp.sources):
        string += "%s$(%s_PROC)%s%s \\\n" % ("" if (c_idx == 0 and s_idx == 0) else "   ",comp.abbr,os.sep,comp.processed[s_idx])
        s_idx += 1

      c_idx += 1

    string += "\n"

    return string
  #}}}

  def str_set_path(self):
  #{{{
    if self.compiler_type == self.C_COMPILER_MS_VS:

      string = "# --- Set compiler path ---\n"
      string += "\n"

      string += "path:\n"
      #string += self.str_message("Setting path to MS_VS compiler")

      if self.shell_type == self.C_SHELL_TYPE_WINDOWS:
        string += "\t$(MS_VS_DIR)%sVC%sbin%svcvars32.bat\n" % (os.sep,os.sep,os.sep)
      else:
        assert False

      return string

    else:
      return ""
  #}}}

  def str_clean(self):
  #{{{
    string = "# --- Configuration clean ---\n"
    string += "\n"

    string += "clean:\n"
    #string += self.str_message("Cleaning : all created files")

    if self.shell_type == self.C_SHELL_TYPE_WINDOWS:
      for clean in self.clean_set:
        if clean[0] == configuration_c.C_CLEAN_DIR:
          string += "\trm -rf \"%s%s*.*\"\n" % (clean[1],os.sep,)
        elif clean[0] == configuration_c.C_CLEAN_FILE:
          string += "\trm -rf \"%s\"\n" % clean[1]
        else:
          assert False

    elif self.shell_type == self.C_SHELL_TYPE_BASH:
      for clean in self.clean_set:
        if clean[0] == configuration_c.C_CLEAN_DIR:
          string += "\trm -rf \"%s%s\"*.*\n" % (clean[1],os.sep,)
        elif clean[0] == configuration_c.C_CLEAN_FILE:
          string += "\trm -rf \"%s\"\n" % clean[1]
        else:
          assert False

    else:
      assert False

    return string
  #}}}

# - CLASS project_c -
class project_c:
  C_INCLUDE_RE = re.compile("[# \t]*include[ \t]*\"")

  def __init__(self, a_conf, a_project_dir, a_abbr, a_header_dirs,
      a_source_dirs, a_lib_dirs, a_cpp_options, a_cpp_link_options,
      a_cpp_defines, a_include_paths, a_lib_paths):
  #{{{
    assert a_conf.__class__ == configuration_c
    self.conf = a_conf

    assert a_project_dir.__class__ == str
    self.project_name = os.path.split(a_project_dir)[1]

    assert a_abbr.__class__ == str
    if a_abbr != "":
      self.abbr = a_abbr.upper()
    else:
      self.abbr = self.project_name.upper()

    self.project_dir = a_project_dir
    self.conf.test_directory(self.project_dir,True)

    self.target = self.project_name

    if self.conf.shell_type == self.conf.C_SHELL_TYPE_WINDOWS:
      self.target += ".exe"

    assert a_cpp_options.__class__ == str and a_cpp_link_options.__class__ == str and a_cpp_defines.__class__ == str
    self.cpp_options = a_cpp_options if a_cpp_options != "" else self.conf.default_cpp_options
    self.cpp_link_options = a_cpp_link_options if a_cpp_link_options != "" else self.conf.default_cpp_link_options
    self.cpp_defines = a_cpp_defines if a_cpp_defines != "" else self.conf.default_cpp_defines

    assert a_header_dirs.__class__ == list
    for h_dir in a_header_dirs:
      assert h_dir.__class__ == str
      self.conf.test_directory(os.path.join(self.project_dir,h_dir),True)
    self.header_dirs = a_header_dirs

    assert a_source_dirs.__class__ == list
    for s_dir in a_source_dirs:
      assert s_dir.__class__ == str
      self.conf.test_directory(os.path.join(self.project_dir,s_dir),True)
    self.source_dirs = a_source_dirs

    assert a_lib_dirs.__class__ == list
    for lib_dir in a_lib_dirs:
      assert lib_dir.__class__ == str
      self.conf.test_directory(os.path.join(self.project_dir,lib_dir),True)
    self.lib_dirs = a_lib_dirs

    self.object_dir = "%s" % self.project_name
    object_dir_path = os.path.join(self.conf.make_dir,self.conf.object_dir,self.object_dir)
    if not os.path.isdir(object_dir_path):
      os.makedirs(object_dir_path)
    self.conf.test_directory(object_dir_path,True)

    self.tmp_dir = "%s" % self.project_name
    tmp_dir_path = os.path.join(self.conf.make_dir,self.conf.tmp_dir,self.tmp_dir)
    if not os.path.isdir(tmp_dir_path):
      os.makedirs(tmp_dir_path)
    self.conf.test_directory(tmp_dir_path,True)

    self.proc_dir = "%s" % self.project_name
    proc_dir_path = os.path.join(self.conf.make_dir,self.conf.proc_dir,self.proc_dir)
    if not os.path.isdir(proc_dir_path):
      os.makedirs(proc_dir_path)
    self.conf.test_directory(proc_dir_path,True)

    assert a_include_paths.__class__ == list
    for include_path in a_include_paths:
      assert include_path.__class__ == str
    self.include_paths = a_include_paths

    assert a_lib_paths.__class__ == list
    for lib_path in a_lib_paths:
      assert lib_path.__class__ == str
    self.lib_paths = a_lib_paths

    self.sources = []
    self.processed = []
    self.objects = []
    self.includes = {}
    self.libraries = []
  #}}}

  def preprocess_source(self,a_source_idx,a_file_name):
  #{{{
    file_f = open(a_file_name)
    for line in file_f:
      if self.C_INCLUDE_RE.match(line):
        include_name = line.split("\"")[1]
        b_found = False
        h_idx = 0
        while h_idx < len(self.header_dirs):
          include_file = os.path.join(self.project_dir,self.header_dirs[h_idx],include_name)
          if os.path.isfile(include_file):
            if not (include_name,h_idx) in self.includes[a_source_idx]:
              self.includes[a_source_idx].append((include_name,h_idx))
              self.preprocess_source(a_source_idx,include_file)

            b_found = True
            break

          h_idx += 1
        
        if not b_found:
          #print >> sys.stderr, "Warning: not found header \"%s\"" % include_name
          pass

    file_f.close()
  #}}}

  def preprocess(self):
  #{{{
    s_idx = 0
    while s_idx < len(self.source_dirs):
      source_dir = os.path.join(self.project_dir,self.source_dirs[s_idx])
      source_names_lst = os.listdir(source_dir)
      for source_name in source_names_lst:
        if os.path.splitext(source_name)[1] in [".cc",".c"]:
          source_file = os.path.join(source_dir,source_name)

          self.sources.append((source_name,s_idx))
          self.processed.append("p.%s" % source_name)

          if self.conf.shell_type == self.conf.C_SHELL_TYPE_WINDOWS:
            self.objects.append("p.%s.obj" % os.path.splitext(source_name)[0])
          elif self.conf.shell_type == self.conf.C_SHELL_TYPE_BASH:
            self.objects.append("p.%s.o" % os.path.splitext(source_name)[0])
          else:
            assert False

          source_idx = len(self.sources) - 1
          self.includes[source_idx] = []
          self.preprocess_source(source_idx,source_file)

      s_idx += 1

    l_idx = 0
    while l_idx < len(self.lib_dirs):
      lib_dir = os.path.join(self.project_dir,self.lib_dirs[l_idx])
      lib_names_lst = os.listdir(lib_dir)
      for lib_name in lib_names_lst:

        if self.conf.shell_type == self.conf.C_SHELL_TYPE_WINDOWS:
          if os.path.splitext(lib_name)[1] == ".dll":
            self.libraries.append(lib_name[:-4])

        elif self.conf.shell_type == self.conf.C_SHELL_TYPE_BASH:
          if os.path.splitext(lib_name)[1] == ".so":
            self.libraries.append(lib_name[3:-3])

        else:
          assert False

      l_idx += 1
  #}}}

  def str_setting(self):
  #{{{
    string = "# --- Project %s setting ---\n" % self.project_name
    string += "\n"

    string += "%s=%s\n" % (self.abbr,self.project_dir)
    string += "\n"

    h_idx = 0
    while h_idx < len(self.header_dirs):
      string += "%s_HEADER_%d=$(%s)%s%s\n" % (self.abbr,h_idx,self.abbr,os.sep,self.header_dirs[h_idx])
      h_idx += 1

    s_idx = 0
    while s_idx < len(self.source_dirs):
      string += "%s_SOURCE_%d=$(%s)%s%s\n" % (self.abbr,s_idx,self.abbr,os.sep,self.source_dirs[s_idx])
      s_idx += 1

    l_idx = 0
    while l_idx < len(self.lib_dirs):
      string += "%s_LIBS_%d=$(%s)%s%s\n" % (self.abbr,l_idx,self.abbr,os.sep,self.lib_dirs[l_idx])
      l_idx += 1

    string += "%s_OBJECT=$(MAKE_OBJECT_DIR)%s%s\n" % (self.abbr,os.sep,self.object_dir)
    string += "%s_TMP=$(MAKE_TMP_DIR)%s%s\n" % (self.abbr,os.sep,self.tmp_dir)
    string += "%s_PROC=$(MAKE_PROC_DIR)%s%s\n" % (self.abbr,os.sep,self.proc_dir)
    string += "\n"

    string += "%s_OPT=%s\n" % (self.abbr,self.cpp_options)

    string += "%s_LINK_OPT=%s\n" % (self.abbr,self.cpp_link_options)

    string += "%s_DEFINES=%s\n" % (self.abbr,self.cpp_defines)
    string += "\n"

    string += "%s_SETTINGS=\\\n" % self.abbr
    
    for include_path in self.include_paths:
      string += "   -I\"%s\"\\\n" % include_path

    h_idx = 0
    while h_idx < len(self.header_dirs):
      string += "   -I\"$(%s_HEADER_%d)\"\\\n" % (self.abbr,h_idx)
      h_idx += 1

    string += "\n"

    string += "%s_LIBS=\\\n" % self.abbr

    # - C_COMPILER_GCC -
    if self.conf.compiler_type == self.conf.C_COMPILER_GCC:

      for lib_path in self.lib_paths:
        string += "   -L\"%s\"\\\n" % lib_path

      l_idx = 0
      while l_idx < len(self.lib_dirs):
        string += "   -L\"$(%s_LIBS_%d)\"\\\n" % (self.abbr,l_idx)
        l_idx += 1

      for library in self.libraries:
        string += "   -l\"%s\"\\\n" % library

    # - C_COMPILER_MS_VS -
    elif self.conf.compiler_type == self.conf.C_COMPILER_MS_VS:

      for lib_path in self.lib_paths:
        string += "   /LIBPATH:%s\\\n" % lib_path

      l_idx = 0
      while l_idx < len(self.lib_dirs):
        string += "   /LIBPATH:$(%s_LIBS_%d)\\\n" % (self.abbr,l_idx)
        l_idx += 1

      for library in self.libraries:
        string += "   \"%s\"\\\n" % library

    else:
      assert False

    return string
  #}}}

  def str_processing(self):
  #{{{
    string = "# --- Project %s processing ---\n" % self.project_name
    string += "\n"

    s_idx = 0
    while s_idx < len(self.sources):
      string += "$(%s_PROC)%s%s:\\\n" % (self.abbr,os.sep,self.processed[s_idx])
      for include in self.includes[s_idx]:
        string += "   $(%s_HEADER_%d)%s%s\\\n" % (self.abbr,include[1],os.sep,include[0])

      string += "   $(%s_SOURCE_%d)%s%s\n" % (self.abbr,self.sources[s_idx][1],os.sep,self.sources[s_idx][0])

      string += self.conf.str_message("Process   : %s : %s" % (self.project_name,self.sources[s_idx][0]))
      string += "\t$(PROC) %s" % self.sources[s_idx][0]

      hd_idx = 0
      while hd_idx < len(self.header_dirs):
        string += " \"$(%s_HEADER_%d)\"" % (self.abbr,hd_idx)
        hd_idx += 1

      sd_idx = 0
      while sd_idx < len(self.source_dirs):
        string += " \"$(%s_SOURCE_%d)\"" % (self.abbr,sd_idx)
        sd_idx += 1

      string += " > \"$(%s_PROC)%s%s\"\n" % (self.abbr,os.sep,self.processed[s_idx])
      string += "\n"

      s_idx += 1

    clean_value = (configuration_c.C_CLEAN_DIR,"$(%s_PROC)" % self.abbr)
    self.conf.clean_set.add(clean_value)

    return string
  #}}}

  def str_compilation(self):
  #{{{
    string = "# --- Project %s compilation ---\n" % self.project_name
    string += "\n"

    p_idx = 0
    while p_idx < len(self.processed):
      string += "$(%s_OBJECT)%s%s:\\\n" % (self.abbr,os.sep,self.objects[p_idx])
      string += "   $(%s_PROC)%s%s\n" % (self.abbr,os.sep,self.processed[p_idx])

      # create compile command
      source_path = os.sep.join([configuration.make_dir,configuration.proc_dir,self.proc_dir,self.processed[p_idx]])
      object_path = os.sep.join([configuration.make_dir,configuration.object_dir,self.object_dir,self.objects[p_idx]])
      cmp_cmds.append({
        "directory":configuration.make_dir,
        "command":"/usr/bin/c++ -c %s %s %s -o %s" % (self.cpp_options,self.cpp_defines,source_path,object_path),
        "file":"%s" % source_path
      })

      if self.conf.compiler_type == self.conf.C_COMPILER_GCC:
        string += self.conf.str_message("Compiling : %s : %s" % (self.project_name,self.processed[p_idx]))
        string += "\t$(CXX) -c $(%s_OPT) $(%s_DEFINES) \"$(%s_PROC)%s%s\" $(%s_SETTINGS) -o \"$(%s_OBJECT)%s%s\"\n" % (self.abbr,self.abbr,self.abbr,os.sep,self.processed[p_idx],self.abbr,self.abbr,os.sep,self.objects[p_idx])
      elif self.conf.compiler_type == self.conf.C_COMPILER_MS_VS:
        string += "\t$(CXX) /c $(%s_OPT) $(%s_DEFINES) \"$(%s_PROC)%s%s\" $(%s_SETTINGS) \"/Fo$(%s_OBJECT)%s%s\"\n" % (self.abbr,self.abbr,self.abbr,os.sep,self.processed[p_idx],self.abbr,self.abbr,os.sep,self.objects[p_idx])
      else:
        assert False

      string += "\n"

      p_idx += 1

    clean_value = (configuration_c.C_CLEAN_DIR,"$(%s_OBJECT)" % self.abbr)
    self.conf.clean_set.add(clean_value)

    return string
  #}}}

  def str_linking(self,a_proj_append):
  #{{{
    assert a_proj_append.__class__ == list
    for app in a_proj_append:
      assert app.__class__ == project_c

    string = "# --- Project %s linking ---\n" % self.project_name
    string += "\n"

    string += "$(%s_TMP)%s%s:\\\n" % (self.abbr,os.sep,self.target)

    obj_line_lst = []

    for proj in a_proj_append:
      o_idx = 0
      while o_idx < len(proj.objects):
        obj_line_lst.append("$(%s_OBJECT)%s%s" % (proj.abbr,os.sep,proj.objects[o_idx]))
        o_idx += 1

    o_idx = 0
    while o_idx < len(self.objects):
      obj_line_lst.append("$(%s_OBJECT)%s%s" % (self.abbr,os.sep,self.objects[o_idx]))
      o_idx += 1

    for obj_line in obj_line_lst[:-1]:
      string += "   %s\\\n" % obj_line
    string += "   %s\n" % obj_line_lst[-1]

    string += self.conf.str_message("Linking   : %s : %s" % (self.project_name,self.target))
    string += "\t$(CXX) $(%s_OPT) $(%s_DEFINES)" % (self.abbr,self.abbr)

    if self.conf.compiler_type == self.conf.C_COMPILER_GCC:
      string += "-o \"$(%s_TMP)%s%s\"\\\n" % (self.abbr,os.sep,self.target)
    elif self.conf.compiler_type == self.conf.C_COMPILER_MS_VS:
      string += "\"/Fe$(%s_TMP)%s%s\"\\\n" % (self.abbr,os.sep,os.path.splitext(self.target)[0])
    else:
      assert False

    for obj_line in obj_line_lst:
      string += "   \"%s\"\\\n" % obj_line

    if self.conf.compiler_type == self.conf.C_COMPILER_GCC:
      string += "   $(%s_LINK_OPT) $(%s_LIBS)  " % (self.abbr,self.abbr)
    elif self.conf.compiler_type == self.conf.C_COMPILER_MS_VS:
      string += "   /link $(%s_LINK_OPT) $(%s_LIBS)  " % (self.abbr,self.abbr)
    else:
      assert False

    for proj in a_proj_append:
      string += "$(%s_LIBS) " % proj.abbr

    string += "\n"

    clean_value = (configuration_c.C_CLEAN_DIR,"$(%s_TMP)" % (self.abbr))
    self.conf.clean_set.add(clean_value)

    return string
  #}}}

  def get_abbr(self):
    return self.abbr

  def get_target(self):
    return self.target

# - CLASS module_c -
class module_c:

  def __init__(self, a_conf, a_module_dir, a_abbr,
      a_header_dirs, a_source_dirs, a_lib_dirs, a_cpp_options,
      a_cpp_link_options, a_cpp_defines, a_include_paths, a_lib_paths):
  #{{{
    self.mod_proj = project_c(a_conf, a_module_dir, a_abbr, a_header_dirs,
        a_source_dirs, a_lib_dirs, a_cpp_options, a_cpp_link_options,
        a_cpp_defines, a_include_paths, a_lib_paths)

    self.mod_proj.target = self.mod_proj.project_name

    if self.mod_proj.conf.shell_type == self.mod_proj.conf.C_SHELL_TYPE_BASH:
      self.mod_proj.target += ".so"
    elif self.mod_proj.conf.shell_type == self.mod_proj.conf.C_SHELL_TYPE_WINDOWS:
      self.mod_proj.target += ".dll"
    else:
      assert False

    shared_link_opt = "-shared -Wl,--soname,%s " % (self.mod_proj.target)
    #shared_link_opt = "-shared -Wl,--soname,$(%s_PROC)%s%s " % (self.mod_proj.abbr,os.sep,self.mod_proj.target)
    self.mod_proj.cpp_link_options = shared_link_opt + self.mod_proj.cpp_link_options
  #}}}

  def preprocess(self):
  #{{{
    self.mod_proj.preprocess()
  #}}}

  def str_setting(self):
  #{{{
    return self.mod_proj.str_setting()
  #}}}

  def str_processing(self):
  #{{{
    return self.mod_proj.str_processing()
  #}}}

  def str_compilation(self):
  #{{{
    return self.mod_proj.str_compilation()
  #}}}

  def str_linking(self,a_proj_append):
  #{{{
    return self.mod_proj.str_linking(a_proj_append)
  #}}}

  def get_abbr(self):
    return self.mod_proj.abbr

  def get_target(self):
    return self.mod_proj.target

# ----- PROGRAM START -----

# configuration
configuration = configuration_c()

# set build and link compiler options
opt_build = "-std=c++11 -O3 -DNDEBUG -fPIC -Wno-class-memaccess " # -DNDEBUG
#opt_build = "-std=c++11 -O3 -msse4.2 -DNDEBUG -fPIC " # -DNDEBUG
opt_link = ""

if configuration.shell_type == configuration.C_SHELL_TYPE_BASH:
  opt_build += "-DLINUX "
elif configuration.shell_type == configuration.C_SHELL_TYPE_WINDOWS:
  opt_build += "-DWINDOWS "
else:
  assert False

if configuration.compiler_type == configuration.C_COMPILER_GCC:
  opt_build += "$(OPT) -Wall "

  if configuration.shell_type == configuration.C_SHELL_TYPE_BASH:
    opt_link += "$(OPT) -ldl -lpthread "
  elif configuration.shell_type == configuration.C_SHELL_TYPE_WINDOWS:
    opt_link += "$(OPT) -lpthread "
  else:
    assert False

elif configuration.compiler_type == configuration.C_COMPILER_MS_VS:
  opt_build += "/nologo /MTd /Os "
  opt_link += "wsock32.lib ws2_32.lib "

else:
  assert False

# uclang project
cfg_ref = c_cfg[C_UCLANG_PROG]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = project_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# node project
cfg_ref = c_cfg[C_NODE_PROG]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = project_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
        os.sep.join(["..","..","libs","libnode_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
        os.sep.join(["..","..","libs","libnode_ucll"]),
      ],
      opt_build, # CXX options
      opt_link,
      "", # CXX defines
      [],
      [],
    )
# }}}

# encipher project
cfg_ref = c_cfg[C_ENCIPHER_PROG]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = project_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# base library
cfg_ref = c_cfg[C_LIBRARY_BASE]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
      ],
      [ 
        "source_files",
      ],
      [],
      opt_build, # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# ftgl library
cfg_ref = c_cfg[C_LIBRARY_FTGL]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
      ],
      [ 
        "source_files",
      ],
      [],
      opt_build + "-I/usr/include/freetype2 ", # CXX options
      opt_link + "-lfreetype -lGLEW -lGL -lglut -lm ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# node library
cfg_ref = c_cfg[C_LIBRARY_NODE]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# base module
cfg_ref = c_cfg[C_MODULE_BASE]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# sys module
cfg_ref = c_cfg[C_MODULE_SYS]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link, # "-lrt " CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# linux module
cfg_ref = c_cfg[C_MODULE_LINUX]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link, # "-lrt " CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# inotify module
cfg_ref = c_cfg[C_MODULE_INOTIFY]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# readline module
cfg_ref = c_cfg[C_MODULE_READLINE]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link + "-lreadline ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# time module
cfg_ref = c_cfg[C_MODULE_TIME]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# lang module
cfg_ref = c_cfg[C_MODULE_LANG]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# pack module
cfg_ref = c_cfg[C_MODULE_PACK]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# cipher module
cfg_ref = c_cfg[C_MODULE_CIPHER]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# parser module
cfg_ref = c_cfg[C_MODULE_PARSER]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# math module
cfg_ref = c_cfg[C_MODULE_MATH]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# gsl module
cfg_ref = c_cfg[C_MODULE_GSL]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link + "-lgsl ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# fftw module
cfg_ref = c_cfg[C_MODULE_FFTW]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link + "-lfftw3 -lm ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# gmp module
cfg_ref = c_cfg[C_MODULE_GMP]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link + "-lgmp -lmpfr ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# datrie module
cfg_ref = c_cfg[C_MODULE_DATRIE]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link + "-ldatrie ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# psql module
cfg_ref = c_cfg[C_MODULE_PSQL]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build + "`pkg-config --cflags libpq` " , # CXX options
      opt_link + "`pkg-config --libs libpq` ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# sqlite module
cfg_ref = c_cfg[C_MODULE_SQLITE]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link + "-lsqlite3 ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# http module
cfg_ref = c_cfg[C_MODULE_HTTP]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link + "-lmicrohttpd ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# websocket module
cfg_ref = c_cfg[C_MODULE_WEBSOCKET]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link + "-lwebsockets ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# curl module
cfg_ref = c_cfg[C_MODULE_CURL]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link + "-lcurl ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# ucf module
cfg_ref = c_cfg[C_MODULE_UCF]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
        os.sep.join(["..","..","..","ext_libs","ucframework","2.15","build","include"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
        os.sep.join(["..","..","..","ext_libs","ucframework","2.15","build","lib"]),
      ],
      opt_build, # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# uctcn module
cfg_ref = c_cfg[C_MODULE_UCTCN]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
        os.sep.join(["..","..","..","ext_libs","ucframework","1.60","build","include"]),
        os.sep.join(["..","..","..","ext_libs","uctcn","2.27","build","include"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
        os.sep.join(["..","..","..","ext_libs","ucframework","1.60","build","lib"]),
        os.sep.join(["..","..","..","ext_libs","uctcn","2.27","build","lib"]),
      ],
      opt_build, # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# uctcnmd module
cfg_ref = c_cfg[C_MODULE_UCTCNMD]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
        os.sep.join(["..","..","..","ext_libs","ucframework","1.60","build","include"]),
        os.sep.join(["..","..","..","ext_libs","uctcn","2.27","build","include"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
        os.sep.join(["..","..","..","ext_libs","ucframework","1.60","build","lib"]),
        os.sep.join(["..","..","..","ext_libs","uctcn","2.27","build","lib"]),
      ],
      opt_build, # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# uctrdp module
cfg_ref = c_cfg[C_MODULE_UCTRDP]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
        os.sep.join(["..","..","..","ext_libs","ucframework","2.15","build","include"]),
        os.sep.join(["..","..","..","ext_libs","uctrdp","1.8","build","include"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
        os.sep.join(["..","..","..","ext_libs","ucframework","2.15","build","lib"]),
        os.sep.join(["..","..","..","ext_libs","uctrdp","1.8","build","lib"]),
      ],
      opt_build, # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# uctrdpmd module
cfg_ref = c_cfg[C_MODULE_UCTRDPMD]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
        os.sep.join(["..","..","..","ext_libs","ucframework","2.15","build","include"]),
        os.sep.join(["..","..","..","ext_libs","uctrdp","1.8","build","include"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
        os.sep.join(["..","..","..","ext_libs","ucframework","2.15","build","lib"]),
        os.sep.join(["..","..","..","ext_libs","uctrdp","1.8","build","lib"]),
      ],
      opt_build, # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# uctrdpns module
cfg_ref = c_cfg[C_MODULE_UCTRDPNS]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
        os.sep.join(["..","..","..","ext_libs","ucframework","2.15","build","include"]),
        os.sep.join(["..","..","..","ext_libs","uctrdp","1.8","build","include"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
        os.sep.join(["..","..","..","ext_libs","ucframework","2.15","build","lib"]),
        os.sep.join(["..","..","..","ext_libs","uctrdp","1.8","build","lib"]),
      ],
      opt_build, # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# uctrdpmsh module
cfg_ref = c_cfg[C_MODULE_UCTRDPMSH]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# uctrndb module
cfg_ref = c_cfg[C_MODULE_UCTRNDB]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
        os.sep.join(["..","..","..","ext_libs","ucframework","2.15","build","include"]),
        os.sep.join(["..","..","..","ext_libs","trndb","trunk","include"]),
        os.sep.join(["..","..","..","ext_libs","astor","trunk"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
        os.sep.join(["..","..","..","ext_libs","ucframework","2.15","build","lib"]),
        os.sep.join(["..","..","..","ext_libs","trndb","trunk","build","build","lib"]),
      ],
      opt_build, # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# uccan module
cfg_ref = c_cfg[C_MODULE_UCCAN]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
        os.sep.join(["..","..","..","ext_libs","ucframework","1.60","build","include"]),
        os.sep.join(["..","..","..","ext_libs","uccanopen","1.14","build","include"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
        os.sep.join(["..","..","..","ext_libs","ucframework","1.60","build","lib"]),
        os.sep.join(["..","..","..","ext_libs","uccanopen","1.14","build","lib"]),
      ],
      opt_build + "-fno-strict-aliasing ", # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# ucmm module
cfg_ref = c_cfg[C_MODULE_UCMM]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
        os.sep.join(["..","..","..","ext_libs","ucmm","trunk","build","include"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
        os.sep.join(["..","..","..","ext_libs","ucmm","trunk","build","lib"]),
      ],
      opt_build, # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# ucgcg module
cfg_ref = c_cfg[C_MODULE_UCGCG]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
        os.sep.join(["..","..","..","ext_libs","ucframework","2.15","build","include"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
        os.sep.join(["..","..","..","ext_libs","ucframework","2.15","build","lib"]),
      ],
      opt_build, # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# adaptrain module
cfg_ref = c_cfg[C_MODULE_ADAPTRAIN]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
        os.sep.join(["..","..","..","ext_libs","ucframework","1.60","build","include"]),
        os.sep.join(["..","..","..","ext_libs","unicon","execnt","src"]),
        os.sep.join(["..","..","..","ext_libs","adaptrain","adaptrain-structs","include"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
        os.sep.join(["..","..","..","ext_libs","ucframework","1.60","build","lib"]),
      ],
      opt_build, # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# ftp module
cfg_ref = c_cfg[C_MODULE_FTP]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link + "-lftp ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# ssh2 module
cfg_ref = c_cfg[C_MODULE_SSH2]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link + "-lssh2 ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# gcrypt module
cfg_ref = c_cfg[C_MODULE_GCRYPT]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link + "-lgcrypt ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# crypto module
cfg_ref = c_cfg[C_MODULE_CRYPTO]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link + "-lcrypto ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# locale module
cfg_ref = c_cfg[C_MODULE_LOCALE]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# iconv module
cfg_ref = c_cfg[C_MODULE_ICONV]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# utf8proc module
cfg_ref = c_cfg[C_MODULE_UTF8PROC]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link + "-lutf8proc ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# jit module
cfg_ref = c_cfg[C_MODULE_JIT]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
        os.sep.join(["..","..","..","ext_libs","libjit","libjit","include"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
        os.sep.join(["..","..","..","ext_libs","libjit","libjit","lib"]),
      ],
      opt_build, # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# lightning module
cfg_ref = c_cfg[C_MODULE_LIGHTNING]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link + "-llightning ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# llvm module
cfg_ref = c_cfg[C_MODULE_LLVM]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build + "-std=c++11 `llvm-config-3.5 --cppflags` ", # CXX options
      opt_link + "`llvm-config-3.5 --ldflags --libs core jit native` -lz -ltinfo ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# ga module
cfg_ref = c_cfg[C_MODULE_GA]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
        os.sep.join(["..","..","..","ext_libs","galib","galib247"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
        os.sep.join(["..","..","..","ext_libs","galib","galib247","ga"]),
      ],
      opt_build, # CXX options
      opt_link + "-lga ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# fann module
cfg_ref = c_cfg[C_MODULE_FANN]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link + "-ldoublefann ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# av module
cfg_ref = c_cfg[C_MODULE_AV]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build + "-D__STDC_CONSTANT_MACROS ", # CXX options
      opt_link + "-lavutil -lavformat -lavcodec -lswscale ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# ao module
cfg_ref = c_cfg[C_MODULE_AO]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link + "-lao ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# mpg module
cfg_ref = c_cfg[C_MODULE_MPG]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link + "-lmpg123 ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# portaudio module
cfg_ref = c_cfg[C_MODULE_PORTAUDIO]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link + "-lportaudio ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# gstreamer module
cfg_ref = c_cfg[C_MODULE_GSTREAMER]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build + "-I/usr/include/gstreamer-1.0 -I/usr/include/libxml2 -I/usr/include/glib-2.0 " +
                  "-I/usr/lib/i386-linux-gnu/glib-2.0/include -I/usr/lib/i386-linux-gnu/gstreamer-1.0/include ", # CXX options
      opt_link + "-lz -lgstreamer-1.0 -lgobject-2.0 -lgmodule-2.0 -lgthread-2.0 -lrt -lxml2 -lglib-2.0 ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# gtk module
cfg_ref = c_cfg[C_MODULE_GTK]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build + "`pkg-config --cflags gtk+-3.0` ", # CXX options
      opt_link + "`pkg-config --libs gtk+-3.0` ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# image module
cfg_ref = c_cfg[C_MODULE_IMAGE]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link + "-lpng -ljpeg ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# opencv module
cfg_ref = c_cfg[C_MODULE_OPENCV]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link + "-lopencv_core -lopencv_imgproc -lopencv_highgui ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# docu module
cfg_ref = c_cfg[C_MODULE_DOCU]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# glut module
cfg_ref = c_cfg[C_MODULE_GLUT]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link + "-lglut ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# glew module
cfg_ref = c_cfg[C_MODULE_GLEW]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link + "-lGLEW ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# gl module
cfg_ref = c_cfg[C_MODULE_GL]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link + "-lGL -lm ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# ftgl module
cfg_ref = c_cfg[C_MODULE_FTGL]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
        os.sep.join(["..","..","libs","libftgl_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
        os.sep.join(["..","..","libs","libftgl_ucll"]),
      ],
      opt_build, # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# vg module
cfg_ref = c_cfg[C_MODULE_VG]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build + "-I/home/jirka/folder/work/programming/git/uclang/ext_libs/AmanithVG/include ", # CXX options
      opt_link + "-L/home/jirka/folder/work/programming/git/uclang/ext_libs/AmanithVG/libs -lAmanithVG ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# shivavg module
cfg_ref = c_cfg[C_MODULE_SHIVAVG]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build + "-I/home/jirka/folder/work/programming/git/uclang/ext_libs/ShivaVG-0.2.1/include ", # CXX options
      opt_link + "-L/home/jirka/folder/work/programming/git/uclang/ext_libs/ShivaVG-0.2.1/src/.libs -lOpenVG -lGL -lGLU ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# amanithvg module
cfg_ref = c_cfg[C_MODULE_AMANITHVG]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build + "-I/home/jirka/folder/work/programming/git/uclang/ext_libs/AmanithVG/include ", # CXX options
      opt_link + "-L/home/jirka/folder/work/programming/git/uclang/ext_libs/AmanithVG/libs -lAmanithVG ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# imxegl module
cfg_ref = c_cfg[C_MODULE_IMXEGL]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
        os.sep.join(["..","..","mods","gl_uclm","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# snmp module
cfg_ref = c_cfg[C_MODULE_SNMP]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link + "-lnetsnmp -lnetsnmpagent ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# comelm module
cfg_ref = c_cfg[C_MODULE_COMELM]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# dlms module
cfg_ref = c_cfg[C_MODULE_DLMS]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
        os.sep.join(["..","..","..","ext_libs","gurux","include"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
        os.sep.join(["..","..","..","ext_libs","gurux","lib"]),
      ],
      opt_build, # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# ucpas module
cfg_ref = c_cfg[C_MODULE_UCPAS]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
        os.sep.join(["..","..","..","ext_libs","ucpas","libpas","src"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
        os.sep.join(["..","..","..","ext_libs","ucpas","libpas"]),
      ],
      opt_build, # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# fgettools module
cfg_ref = c_cfg[C_MODULE_FGETTOOLS]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# node module
cfg_ref = c_cfg[C_MODULE_NODE]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
        os.sep.join(["..","..","libs","libnode_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
        os.sep.join(["..","..","libs","libnode_ucll"]),
      ],
      opt_build, # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# ddb module
cfg_ref = c_cfg[C_MODULE_DDB]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# containers module
cfg_ref = c_cfg[C_MODULE_CONTAINERS]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# algorithms module
cfg_ref = c_cfg[C_MODULE_ALGORITHMS]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# validator module
cfg_ref = c_cfg[C_MODULE_VALIDATOR]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# binbits module
cfg_ref = c_cfg[C_MODULE_BINBITS]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# graph module
cfg_ref = c_cfg[C_MODULE_GRAPH]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# json module
cfg_ref = c_cfg[C_MODULE_JSON]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# xml module
cfg_ref = c_cfg[C_MODULE_XML]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build + "-I/usr/include/libxml2 ", # CXX options
      opt_link + "-lxml2 ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# intelhex module
cfg_ref = c_cfg[C_MODULE_INTELHEX]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# soapcl module
cfg_ref = c_cfg[C_MODULE_SOAPCL]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link + "-lgsoap ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# soapsrv module
cfg_ref = c_cfg[C_MODULE_SOAPSRV]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link + "-lgsoap ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# python module
cfg_ref = c_cfg[C_MODULE_PYTHON]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build + "-I/usr/include/python2.7 ", # CXX options, -DPy_DEBUG
      opt_link + "-lpython2.7 ", # CXX link options, -lpython2.7_d
      "", # CXX defines
      [],
      [],
    )
# }}}

# v8 module
cfg_ref = c_cfg[C_MODULE_V8]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link + "-lv8 ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# lua module
cfg_ref = c_cfg[C_MODULE_LUA]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link + "-llua5.2 ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# mono module
cfg_ref = c_cfg[C_MODULE_MONO]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build + "-I/usr/include/glib-2.0 -I/usr/lib/i386-linux-gnu/glib-2.0/include -I/usr/include/mono-2.0 ", # CXX options
      opt_link + "-lmonosgen-2.0 ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# perl module
cfg_ref = c_cfg[C_MODULE_PERL]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build + "-I/usr/lib/i386-linux-gnu/perl/5.28.0/CORE ", # CXX options
      opt_link + "-L/usr/lib/i386-linux-gnu -lperl ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# ruby module
cfg_ref = c_cfg[C_MODULE_RUBY]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build + "-I/usr/include/ruby-2.5.0 -I/usr/include/i386-linux-gnu/ruby-2.5.0 ", # CXX options
      opt_link + "-L/usr/lib/i386-linux-gnu -lruby-2.5 ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# prolog module
cfg_ref = c_cfg[C_MODULE_PROLOG]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build + "`pkg-config --cflags swipl` ", # CXX options
      opt_link + "`pkg-config --libs swipl` ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# rust module
cfg_ref = c_cfg[C_MODULE_RUST]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","libs","libbase_ucll"]),
        os.sep.join(["rs","target","release"]),
      ],
      opt_build, # CXX options
      opt_link + "-lrust_ruclm ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# uv module
cfg_ref = c_cfg[C_MODULE_UV]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link + "-luv ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# zlib module
cfg_ref = c_cfg[C_MODULE_ZLIB]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link + "-lz ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# zip module
cfg_ref = c_cfg[C_MODULE_ZIP]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link + "-lzip ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# snappy module
cfg_ref = c_cfg[C_MODULE_SNAPPY]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link + "-lsnappy ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# pigpio module
cfg_ref = c_cfg[C_MODULE_PIGPIO]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link + "-lpigpio ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# fuse module
cfg_ref = c_cfg[C_MODULE_FUSE]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build + "-D_FILE_OFFSET_BITS=64 ", # CXX options
      opt_link + "-lfuse ", # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# android module
cfg_ref = c_cfg[C_MODULE_ANDROID]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# nacl module
cfg_ref = c_cfg[C_MODULE_NACL]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# emscripten module
cfg_ref = c_cfg[C_MODULE_EMSCRIPTEN]
# {{{
if cfg_ref[CFG_TARGET]:
    cfg_ref[CFG_MODULE] = module_c(
      configuration,
      cfg_ref[CFG_DIR],
      cfg_ref[CFG_NAME],
      [ 
        "header_files",
        os.sep.join(["..","..","libs","libbase_ucll","header_files"]),
      ],
      [ 
        "source_files",
      ],
      [
        os.sep.join(["..","..","libs","libbase_ucll"]),
      ],
      opt_build, # CXX options
      opt_link, # CXX link options
      "", # CXX defines
      [],
      [],
    )
# }}}

# list of compilation commands
cmp_cmds = [];

# compilation target selection
if len(sys.argv) > 1:
    selection = sys.argv[1::]
    config = []
    for comp in c_cfg:
        if comp[CFG_NAME] in selection:
            config.append(comp)

else:
    config = c_cfg

# preprocess
for comp in config:
    if comp[CFG_TARGET]:
        comp[CFG_MODULE].preprocess()

print
print configuration.str_setting()

for comp in config:
    if comp[CFG_TARGET]:
        print comp[CFG_MODULE].str_setting()

all_target_list = []
proc_target_list = []
for comp in config:
    if comp[CFG_TARGET]:

        # append component to compilation target list
        all_target_list.append(comp[CFG_MODULE])

        # append component to process target list
        proc_target_list.append(comp[CFG_MODULE])

print configuration.str_all_target(all_target_list)
print configuration.str_process_target(proc_target_list)

for comp in config:
    if comp[CFG_TARGET]:
        print comp[CFG_MODULE].str_processing()

for comp in config:
    if comp[CFG_TARGET]:
        print comp[CFG_MODULE].str_compilation()

for comp in config:
    if comp[CFG_TARGET]:
        print comp[CFG_MODULE].str_linking([])

print configuration.str_set_path()
print configuration.str_clean()

# write compile commands to file
ccf = open('compile_commands.json','w')
ccf.write(json.dumps(cmp_cmds,indent=2))
ccf.close()

