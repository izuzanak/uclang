#!/bin/bash

# Generate base documentation

./uclang scripts/docu_gen.ucl Blank ../uclang/doc/02_modules/02_module_base/01_class_blank.md
./uclang scripts/docu_gen.ucl Char ../uclang/doc/02_modules/02_module_base/02_class_char.md
./uclang scripts/docu_gen.ucl Integer ../uclang/doc/02_modules/02_module_base/03_class_integer.md
./uclang scripts/docu_gen.ucl Float ../uclang/doc/02_modules/02_module_base/04_class_float.md
./uclang scripts/docu_gen.ucl String ../uclang/doc/02_modules/02_module_base/05_class_string.md containers
./uclang scripts/docu_gen.ucl Array ../uclang/doc/02_modules/02_module_base/06_class_array.md
#./uclang scripts/docu_gen.ucl Error ../uclang/doc/02_modules/02_module_base/07_class_error.md
#./uclang scripts/docu_gen.ucl Exception ../uclang/doc/02_modules/02_module_base/08_class_exception.md
#./uclang scripts/docu_gen.ucl Type ../uclang/doc/02_modules/02_module_base/09_class_type.md
#./uclang scripts/docu_gen.ucl Mutex ../uclang/doc/02_modules/02_module_base/10_class_mutex.md
#./uclang scripts/docu_gen.ucl Thread ../uclang/doc/02_modules/02_module_base/11_class_thread.md
#./uclang scripts/docu_gen.ucl Delegate ../uclang/doc/02_modules/02_module_base/12_class_delegate.md
#./uclang scripts/docu_gen.ucl Buffer ../uclang/doc/02_modules/02_module_base/13_class_buffer.md

# Generate containers documentation
./uclang scripts/docu_gen.ucl Stack ../uclang/doc/02_modules/03_module_containers/01_class_stack.md containers
./uclang scripts/docu_gen.ucl Queue ../uclang/doc/02_modules/03_module_containers/02_class_queue.md containers
./uclang scripts/docu_gen.ucl Set ../uclang/doc/02_modules/03_module_containers/03_class_set.md containers
./uclang scripts/docu_gen.ucl List ../uclang/doc/02_modules/03_module_containers/04_class_list.md containers
./uclang scripts/docu_gen.ucl Tree ../uclang/doc/02_modules/03_module_containers/05_class_tree.md containers
./uclang scripts/docu_gen.ucl Dict ../uclang/doc/02_modules/03_module_containers/06_class_dict.md containers

# Generate parser documentation
./uclang scripts/docu_gen.ucl FinalAutomata ../uclang/doc/02_modules/05_module_parser/01_class_final_automata.md parser
./uclang scripts/docu_gen.ucl FaSource ../uclang/doc/02_modules/05_module_parser/02_class_fa_source.md parser
# HM ./uclang scripts/docu_gen.ucl Parser ../uclang/doc/02_modules/05_module_parser/03_class_parser.md parser
# HM ./uclang scripts/docu_gen.ucl ParseState ../uclang/doc/02_modules/05_module_parser/04_class_parse_state.md parser

