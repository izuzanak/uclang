#!/bin/bash

# Generate base documentation

./uclang scripts/docu_gen.ucl Blank ../uclang/doc/02_modules/02_module_base/01_class_blank.md
./uclang scripts/docu_gen.ucl Char ../uclang/doc/02_modules/02_module_base/02_class_char.md
./uclang scripts/docu_gen.ucl Integer ../uclang/doc/02_modules/02_module_base/03_class_integer.md
./uclang scripts/docu_gen.ucl Float ../uclang/doc/02_modules/02_module_base/04_class_float.ucl
./uclang scripts/docu_gen.ucl String ../uclang/doc/02_modules/02_module_base/05_class_string.ucl containers
./uclang scripts/docu_gen.ucl Array ../uclang/doc/02_modules/02_module_base/06_class_array.ucl
#./uclang scripts/docu_gen.ucl Error ../uclang/doc/02_modules/02_module_base/07_class_error.ucl
#./uclang scripts/docu_gen.ucl Exception ../uclang/doc/02_modules/02_module_base/08_class_exception.ucl
#./uclang scripts/docu_gen.ucl Type ../uclang/doc/02_modules/02_module_base/09_class_type.ucl
#./uclang scripts/docu_gen.ucl Mutex ../uclang/doc/02_modules/02_module_base/10_class_mutex.ucl
#./uclang scripts/docu_gen.ucl Thread ../uclang/doc/02_modules/02_module_base/11_class_thread.ucl
#./uclang scripts/docu_gen.ucl Delegate ../uclang/doc/02_modules/02_module_base/12_class_delegate.ucl
#./uclang scripts/docu_gen.ucl Buffer ../uclang/doc/02_modules/02_module_base/13_class_buffer.ucl

# Generate containers documentation
./uclang scripts/docu_gen.ucl Stack ../uclang/doc/02_modules/03_module_containers/01_class_stack.md containers
./uclang scripts/docu_gen.ucl Queue ../uclang/doc/02_modules/03_module_containers/02_class_queue.md containers
./uclang scripts/docu_gen.ucl Set ../uclang/doc/02_modules/03_module_containers/03_class_set.md containers
./uclang scripts/docu_gen.ucl List ../uclang/doc/02_modules/03_module_containers/04_class_list.md containers
./uclang scripts/docu_gen.ucl Tree ../uclang/doc/02_modules/03_module_containers/05_class_tree.md containers
./uclang scripts/docu_gen.ucl Dict ../uclang/doc/02_modules/03_module_containers/06_class_dict.md containers

