
#ifndef __JSON_PARSE_ACTIONS_H
#define __JSON_PARSE_ACTIONS_H

/*
 * declaration of function describing parse actions
 */

bool pa_json_null(json_parser_s &_this);
bool pa_json_object_begin(json_parser_s &_this);
bool pa_json_object_pair(json_parser_s &_this);
bool pa_json_array_begin(json_parser_s &_this);
bool pa_json_array_value(json_parser_s &_this);
bool pa_json_val_string(json_parser_s &_this);
bool pa_json_val_integer(json_parser_s &_this);
bool pa_json_val_float(json_parser_s &_this);
bool pa_json_val_object(json_parser_s &_this);
bool pa_json_val_array(json_parser_s &_this);
bool pa_json_val_true(json_parser_s &_this);
bool pa_json_val_false(json_parser_s &_this);
bool pa_json_val_null(json_parser_s &_this);
bool pa_json_string(json_parser_s &_this);

/*
 * access to function callers
 */

extern bool(*json_pa_callers[])(json_parser_s &_this);

#endif

