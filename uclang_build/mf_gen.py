#!/usr/bin/python
#VERSION #3

import sys,os
import re

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
      #string += "GPP=clang++\n"
      string += "GPP=g++\n"
    elif self.compiler_type == self.C_COMPILER_MS_VS:
      string += "GPP=cl\n"
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

      if self.conf.compiler_type == self.conf.C_COMPILER_GCC:
        string += self.conf.str_message("Compiling : %s : %s" % (self.project_name,self.processed[p_idx]))
        string += "\t$(GPP) -c $(%s_OPT) $(%s_DEFINES) \"$(%s_PROC)%s%s\" $(%s_SETTINGS) -o \"$(%s_OBJECT)%s%s\"\n" % (self.abbr,self.abbr,self.abbr,os.sep,self.processed[p_idx],self.abbr,self.abbr,os.sep,self.objects[p_idx])
      elif self.conf.compiler_type == self.conf.C_COMPILER_MS_VS:
        string += "\t$(GPP) /c $(%s_OPT) $(%s_DEFINES) \"$(%s_PROC)%s%s\" $(%s_SETTINGS) \"/Fo$(%s_OBJECT)%s%s\"\n" % (self.abbr,self.abbr,self.abbr,os.sep,self.processed[p_idx],self.abbr,self.abbr,os.sep,self.objects[p_idx])
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
    string += "\t$(GPP) $(%s_OPT) $(%s_DEFINES)" % (self.abbr,self.abbr)

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
opt_build = "-O2 -DNDEBUG -ffast-math -fPIC " # -DNDEBUG
opt_link = ""

if configuration.shell_type == configuration.C_SHELL_TYPE_BASH:
  opt_build += "-DLINUX "
elif configuration.shell_type == configuration.C_SHELL_TYPE_WINDOWS:
  opt_build += "-DWINDOWS "
else:
  assert False

if configuration.compiler_type == configuration.C_COMPILER_GCC:
  opt_build += "$(OPT) -Wall -fno-strict-aliasing "

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
        os.sep.join(["..","..","libs","libbase_ucll"])
      ],
      opt_build, # GPP options
      opt_link, # GPP link options
      "", # GPP defines
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
      opt_build, # GPP options
      opt_link,
      "", # GPP defines
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
        os.sep.join(["..","..","libs","libbase_ucll"])
      ],
      opt_build, # GPP options
      opt_link, # GPP link options
      "", # GPP defines
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
      opt_build, # GPP options
      opt_link, # GPP link options
      "", # GPP defines
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
      opt_build + "-I/usr/include/freetype2 ", # GPP options
      opt_link + "-lfreetype -lGLEW -lGL -lglut -lm ", # GPP link options
      "", # GPP defines
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
        os.sep.join(["..","libbase_ucll"])
      ],
      opt_build, # GPP options
      opt_link, # GPP link options
      "", # GPP defines
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
        os.sep.join(["..","..","libs","libbase_ucll"])
      ],
      opt_build, # GPP options
      opt_link, # GPP link options
      "", # GPP defines
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
        os.sep.join(["..","..","libs","libbase_ucll"])
      ],
      opt_build, # GPP options
      opt_link, # "-lrt " GPP link options
      "", # GPP defines
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
        os.sep.join(["..","..","libs","libbase_ucll"])
      ],
      opt_build, # GPP options
      opt_link, # GPP link options
      "", # GPP defines
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
        os.sep.join(["..","..","libs","libbase_ucll"])
      ],
      opt_build, # GPP options
      opt_link, # GPP link options
      "", # GPP defines
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
        os.sep.join(["..","..","libs","libbase_ucll"])
      ],
      opt_build, # GPP options
      opt_link, # GPP link options
      "", # GPP defines
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
        os.sep.join(["..","..","libs","libbase_ucll"])
      ],
      opt_build, # GPP options
      opt_link, # GPP link options
      "", # GPP defines
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
        os.sep.join(["..","..","libs","libbase_ucll"])
      ],
      opt_build, # GPP options
      opt_link, # GPP link options
      "", # GPP defines
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
        os.sep.join(["..","..","libs","libbase_ucll"])
      ],
      opt_build, # GPP options
      opt_link, # GPP link options
      "", # GPP defines
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
        os.sep.join(["..","..","libs","libbase_ucll"])
      ],
      opt_build, # GPP options
      opt_link, # GPP link options
      "", # GPP defines
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
        os.sep.join(["..","..","libs","libbase_ucll"])
      ],
      opt_build, # GPP options
      opt_link + "-lpq ", # GPP link options
      "", # GPP defines
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
        os.sep.join(["..","..","libs","libbase_ucll"])
      ],
      opt_build, # GPP options
      opt_link + "-lsqlite3 ", # GPP link options
      "", # GPP defines
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
        os.sep.join(["..","..","libs","libbase_ucll"])
      ],
      opt_build, # GPP options
      opt_link + "-lmicrohttpd ", # GPP link options
      "", # GPP defines
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
        os.sep.join(["..","..","libs","libbase_ucll"])
      ],
      opt_build, # GPP options
      opt_link + "-lwebsockets ", # GPP link options
      "", # GPP defines
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
        os.sep.join(["..","..","libs","libbase_ucll"])
      ],
      opt_build, # GPP options
      opt_link + "-lcurl ", # GPP link options
      "", # GPP defines
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
        os.sep.join(["..","..","..","ext_libs","ucframework","2.9","build","include"]),
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
        os.sep.join(["..","..","..","ext_libs","ucframework","2.9","build","lib"]),
      ],
      opt_build, # GPP options
      opt_link, # GPP link options
      "", # GPP defines
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
        os.sep.join(["..","..","..","ext_libs","uctcn","2.27","build","include"])
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
        os.sep.join(["..","..","..","ext_libs","ucframework","1.60","build","lib"]),
        os.sep.join(["..","..","..","ext_libs","uctcn","2.27","build","lib"])
      ],
      opt_build, # GPP options
      opt_link, # GPP link options
      "", # GPP defines
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
        os.sep.join(["..","..","..","ext_libs","ucmm","trunk","build","include"])
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
        os.sep.join(["..","..","..","ext_libs","ucmm","trunk","build","lib"])
      ],
      opt_build, # GPP options
      opt_link, # GPP link options
      "", # GPP defines
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
      opt_build, # GPP options
      opt_link, # GPP link options
      "", # GPP defines
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
      opt_build, # GPP options
      opt_link + "-lftp ", # GPP link options
      "", # GPP defines
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
      opt_build, # GPP options
      opt_link + "-lssh2 ", # GPP link options
      "", # GPP defines
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
      opt_build, # GPP options
      opt_link + "-lgcrypt ", # GPP link options
      "", # GPP defines
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
      opt_build, # GPP options
      opt_link, # GPP link options
      "", # GPP defines
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
        os.sep.join(["..","..","..","ext_libs","libjit","libjit","include"])
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
        os.sep.join(["..","..","..","ext_libs","libjit","libjit","lib"])
      ],
      opt_build, # GPP options
      opt_link, # GPP link options
      "", # GPP defines
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
        os.sep.join(["..","..","libs","libbase_ucll","header_files"])
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"])
      ],
      opt_build, # GPP options
      opt_link + "-llightning ", # GPP link options
      "", # GPP defines
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
        os.sep.join(["..","..","libs","libbase_ucll","header_files"])
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"])
      ],
      opt_build + "-std=c++11 `llvm-config --cppflags` ", # GPP options
      opt_link + "`llvm-config --ldflags --libs core jit native` -lz -ltinfo ", # GPP link options
      "", # GPP defines
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
      opt_build, # GPP options
      opt_link + "-lga ", # GPP link options
      "", # GPP defines
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
      opt_build + "-D__STDC_CONSTANT_MACROS ", # GPP options
      opt_link + "-lavutil -lavformat -lavcodec -lswscale ", # GPP link options
      "", # GPP defines
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
      opt_build, # GPP options
      opt_link + "-lao ", # GPP link options
      "", # GPP defines
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
      opt_build, # GPP options
      opt_link + "-lmpg123 ", # GPP link options
      "", # GPP defines
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
      opt_build, # GPP options
      opt_link + "-lportaudio ", # GPP link options
      "", # GPP defines
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
      opt_build + "-I/usr/include/gstreamer-1.0 -I/usr/include/libxml2 -I/usr/include/glib-2.0 -I/usr/lib/i386-linux-gnu/glib-2.0/include", # GPP options
      opt_link + "-lz -lgstreamer-1.0 -lgobject-2.0 -lgmodule-2.0 -lgthread-2.0 -lrt -lxml2 -lglib-2.0 ", # GPP link options
      "", # GPP defines
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
      opt_build, # GPP options
      opt_link + "-lpng -ljpeg", # GPP link options
      "", # GPP defines
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
      opt_build, # GPP options
      opt_link + "-lopencv_core -lopencv_imgproc -lopencv_highgui ", # GPP link options
      "", # GPP defines
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
      opt_build, # GPP options
      opt_link, # GPP link options
      "", # GPP defines
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
      opt_build, # GPP options
      opt_link + "-lglut ", # GPP link options
      "", # GPP defines
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
      opt_build, # GPP options
      opt_link + "-lGLEW ", # GPP link options
      "", # GPP defines
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
      opt_build, # GPP options
      opt_link + "-lGL -lm ", # GPP link options
      "", # GPP defines
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
      opt_build, # GPP options
      opt_link, # GPP link options
      "", # GPP defines
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
      opt_build, # GPP options
      opt_link, # GPP link options
      "", # GPP defines
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
      opt_build, # GPP options
      opt_link, # GPP link options
      "", # GPP defines
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
      opt_build, # GPP options
      opt_link + "-lnetsnmp -lnetsnmpagent ", # GPP link options
      "", # GPP defines
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
      opt_build, # GPP options
      opt_link, # GPP link options
      "", # GPP defines
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
        os.sep.join(["..","..","..","ext_libs","ucpas","libpas","src"])
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"]),
        os.sep.join(["..","..","..","ext_libs","ucpas","libpas"])
      ],
      opt_build, # GPP options
      opt_link, # GPP link options
      "", # GPP defines
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
        os.sep.join(["..","..","libs","libbase_ucll","header_files"])
      ],
      [ 
        "source_files",
      ],
      [ 
        os.sep.join(["..","..","libs","libbase_ucll"])
      ],
      opt_build, # GPP options
      opt_link, # GPP link options
      "", # GPP defines
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
      opt_build, # GPP options
      opt_link, # GPP link options
      "", # GPP defines
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
      opt_build, # GPP options
      opt_link, # GPP link options
      "", # GPP defines
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
        os.sep.join(["..","..","libs","libbase_ucll"])
      ],
      opt_build, # GPP options
      opt_link, # GPP link options
      "", # GPP defines
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
        os.sep.join(["..","..","libs","libbase_ucll"])
      ],
      opt_build, # GPP options
      opt_link, # GPP link options
      "", # GPP defines
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
        os.sep.join(["..","..","libs","libbase_ucll"])
      ],
      opt_build, # GPP options
      opt_link, # GPP link options
      "", # GPP defines
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
        os.sep.join(["..","..","libs","libbase_ucll"])
      ],
      opt_build, # GPP options
      opt_link, # GPP link options
      "", # GPP defines
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
        os.sep.join(["..","..","libs","libbase_ucll"])
      ],
      opt_build + "-I/usr/include/libxml2 ", # GPP options
      opt_link + "-lxml2 ", # GPP link options
      "", # GPP defines
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
        os.sep.join(["..","..","..","libs","libbase_ucll"])
      ],
      opt_build, # GPP options
      opt_link + "-lgsoap ", # GPP link options
      "", # GPP defines
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
        os.sep.join(["..","..","..","libs","libbase_ucll"])
      ],
      opt_build, # GPP options
      opt_link + "-lgsoap ", # GPP link options
      "", # GPP defines
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
        os.sep.join(["..","..","libs","libbase_ucll"])
      ],
      opt_build + "-I/usr/include/python2.7 ", # GPP options, -DPy_DEBUG
      opt_link + "-lpython2.7 ", # GPP link options, -lpython2.7_d
      "", # GPP defines
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
        os.sep.join(["..","..","libs","libbase_ucll"])
      ],
      opt_build, # GPP options
      opt_link + "-lv8 ", # GPP link options
      "", # GPP defines
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
        os.sep.join(["..","..","libs","libbase_ucll"])
      ],
      opt_build, # GPP options
      opt_link + "-llua5.2 ", # GPP link options
      "", # GPP defines
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
        os.sep.join(["..","..","libs","libbase_ucll"])
      ],
      opt_build, # GPP options
      opt_link + "-luv ", # GPP link options
      "", # GPP defines
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
        os.sep.join(["..","..","libs","libbase_ucll"])
      ],
      opt_build + "-D_FILE_OFFSET_BITS=64 ", # GPP options
      opt_link + "-lfuse ", # GPP link options
      "", # GPP defines
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
        os.sep.join(["..","..","libs","libbase_ucll"])
      ],
      opt_build, # GPP options
      opt_link, # GPP link options
      "", # GPP defines
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
        os.sep.join(["..","..","libs","libbase_ucll"])
      ],
      opt_build, # GPP options
      opt_link, # GPP link options
      "", # GPP defines
      [],
      [],
    )
# }}}

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

