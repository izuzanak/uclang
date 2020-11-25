#!/bin/bash

mkdir -p snippets

# Generate base documentation
uclang scripts/docu_gen.ucl Blank ../uclang/doc/02_modules/02_module_base/01_class_blank.md
uclang scripts/docu_gen.ucl Char ../uclang/doc/02_modules/02_module_base/02_class_char.md
uclang scripts/docu_gen.ucl Integer ../uclang/doc/02_modules/02_module_base/03_class_integer.md
uclang scripts/docu_gen.ucl Float ../uclang/doc/02_modules/02_module_base/04_class_float.md
uclang scripts/docu_gen.ucl String ../uclang/doc/02_modules/02_module_base/05_class_string.md containers
uclang scripts/docu_gen.ucl Array ../uclang/doc/02_modules/02_module_base/06_class_array.md
uclang scripts/docu_gen.ucl Error ../uclang/doc/02_modules/02_module_base/07_class_error.md
uclang scripts/docu_gen.ucl Exception ../uclang/doc/02_modules/02_module_base/08_class_exception.md
uclang scripts/docu_gen.ucl Type ../uclang/doc/02_modules/02_module_base/09_class_type.md
uclang scripts/docu_gen.ucl Mutex ../uclang/doc/02_modules/02_module_base/10_class_mutex.md
uclang scripts/docu_gen.ucl Thread ../uclang/doc/02_modules/02_module_base/11_class_thread.md sys
uclang scripts/docu_gen.ucl Delegate ../uclang/doc/02_modules/02_module_base/12_class_delegate.md
#./uclang scripts/docu_gen.ucl Buffer ../uclang/doc/02_modules/02_module_base/13_class_buffer.md

# Generate containers documentation
uclang scripts/docu_gen.ucl Stack ../uclang/doc/02_modules/03_module_containers/01_class_stack.md containers
uclang scripts/docu_gen.ucl Queue ../uclang/doc/02_modules/03_module_containers/02_class_queue.md containers
uclang scripts/docu_gen.ucl Set ../uclang/doc/02_modules/03_module_containers/03_class_set.md containers
uclang scripts/docu_gen.ucl List ../uclang/doc/02_modules/03_module_containers/04_class_list.md containers
uclang scripts/docu_gen.ucl Tree ../uclang/doc/02_modules/03_module_containers/05_class_tree.md containers
uclang scripts/docu_gen.ucl Dict ../uclang/doc/02_modules/03_module_containers/06_class_dict.md containers

# Generate sys documentation
#./uclang scripts/docu_gen.ucl Sys ../uclang/doc/02_modules/04_module_sys/01_class_sys.md sys:time
uclang scripts/docu_gen.ucl Pipe ../uclang/doc/02_modules/04_module_sys/02_class_pipe.md sys
uclang scripts/docu_gen.ucl File ../uclang/doc/02_modules/04_module_sys/03_class_file.md sys
#./uclang scripts/docu_gen.ucl Socket ../uclang/doc/02_modules/04_module_sys/04_class_socket.md sys
#./uclang scripts/docu_gen.ucl Regex ../uclang/doc/02_modules/04_module_sys/05_class_regex.md sys
#./uclang scripts/docu_gen.ucl Signal ../uclang/doc/02_modules/04_module_sys/06_class_signal.md sys
#./uclang scripts/docu_gen.ucl Poll ../uclang/doc/02_modules/04_module_sys/007_class_poll.md sys
#./uclang scripts/docu_gen.ucl Timer ../uclang/doc/02_modules/04_module_sys/008_class_timer.md sys
#./uclang scripts/docu_gen.ucl Clock ../uclang/doc/02_modules/04_module_sys/009_class_clock.md sys

# Generate parser documentation
uclang scripts/docu_gen.ucl FinalAutomata ../uclang/doc/02_modules/05_module_parser/01_class_final_automata.md parser
uclang scripts/docu_gen.ucl FaSource ../uclang/doc/02_modules/05_module_parser/02_class_fa_source.md parser
uclang scripts/docu_gen.ucl Parser ../uclang/doc/02_modules/05_module_parser/03_class_parser.md parser
uclang scripts/docu_gen.ucl ParseState ../uclang/doc/02_modules/05_module_parser/04_class_parse_state.md parser

# Generate pack documentation
uclang scripts/docu_gen.ucl Pack ../uclang/doc/02_modules/06_module_pack/01_class_pack.md containers:pack

# Generate algorithms documentation
uclang scripts/docu_gen.ucl Algo ../uclang/doc/02_modules/07_module_algorithms/01_class_algo.md containers:algorithms
uclang scripts/docu_gen.ucl Filter ../uclang/doc/02_modules/07_module_algorithms/02_class_filter.md containers:algorithms
uclang scripts/docu_gen.ucl Range ../uclang/doc/02_modules/07_module_algorithms/03_class_range.md containers:algorithms

# Generate json documentation
uclang scripts/docu_gen.ucl Json ../uclang/doc/02_modules/08_module_json/01_class_json.md containers:json

