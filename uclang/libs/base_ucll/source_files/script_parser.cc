
@begin
include "script_parser.h"
@end

/*
 * constants and definitions
 */

/*
 * LALR parse table
 */
const unsigned lalr_table[lalr_state_cnt*c_terminal_plus_nonterminal_cnt] =
{/*{{{*/
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,    SHIFT(7),   SHIFT(12),   SHIFT(13),   SHIFT(23),       blank,   SHIFT(16),   SHIFT(17),   SHIFT(18),   SHIFT(19),   SHIFT(20),   SHIFT(21),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,    SHIFT(3),       blank,     GOTO(1),     GOTO(2),     GOTO(4),     GOTO(5),    GOTO(14),     GOTO(6),     GOTO(8),     GOTO(9),    GOTO(10),       blank,       blank,       blank,    GOTO(11),    GOTO(15),    GOTO(22),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(24),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   REDUCE(3),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,    SHIFT(7),   SHIFT(12),   SHIFT(13),   SHIFT(23),       blank,   SHIFT(16),   SHIFT(17),   SHIFT(18),   SHIFT(19),   SHIFT(20),   SHIFT(21),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,    GOTO(25),     GOTO(5),    GOTO(14),     GOTO(6),     GOTO(8),     GOTO(9),    GOTO(10),       blank,       blank,       blank,    GOTO(11),    GOTO(15),    GOTO(22),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   REDUCE(5),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(26),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(12),   SHIFT(13),   SHIFT(23),       blank,   SHIFT(16),   SHIFT(17),   SHIFT(18),   SHIFT(19),   SHIFT(20),   SHIFT(21),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   REDUCE(8),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   REDUCE(8),       blank,       blank,       blank,       blank,       blank,    GOTO(14),    GOTO(27),     GOTO(8),     GOTO(9),    GOTO(10),       blank,       blank,       blank,    GOTO(11),    GOTO(15),    GOTO(22),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(28),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(29),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(18),  REDUCE(18),  REDUCE(18),       blank,  REDUCE(18),  REDUCE(18),  REDUCE(18),  REDUCE(18),  REDUCE(18),  REDUCE(18),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(18),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(18),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(32),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,    GOTO(30),    GOTO(31),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(33),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(23),       blank,   SHIFT(16),   SHIFT(17),   SHIFT(18),   SHIFT(19),   SHIFT(20),   SHIFT(21),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,    GOTO(14),       blank,       blank,       blank,       blank,       blank,       blank,       blank,    GOTO(34),    GOTO(15),    GOTO(22),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(26),  REDUCE(26),  REDUCE(26),       blank,  REDUCE(26),  REDUCE(26),  REDUCE(26),  REDUCE(26),  REDUCE(26),  REDUCE(26),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(26),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(26),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(19),       blank,       blank,       blank,  REDUCE(19),       blank,  REDUCE(19),  REDUCE(19),  REDUCE(19),  REDUCE(19),  REDUCE(19),  REDUCE(19),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(20),       blank,       blank,       blank,  REDUCE(20),       blank,  REDUCE(20),  REDUCE(20),  REDUCE(20),  REDUCE(20),  REDUCE(20),  REDUCE(20),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(21),       blank,       blank,       blank,  REDUCE(21),       blank,  REDUCE(21),  REDUCE(21),  REDUCE(21),  REDUCE(21),  REDUCE(21),  REDUCE(21),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(22),       blank,       blank,       blank,  REDUCE(22),       blank,  REDUCE(22),  REDUCE(22),  REDUCE(22),  REDUCE(22),  REDUCE(22),  REDUCE(22),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(23),       blank,       blank,       blank,  REDUCE(23),       blank,  REDUCE(23),  REDUCE(23),  REDUCE(23),  REDUCE(23),  REDUCE(23),  REDUCE(23),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(24),       blank,       blank,       blank,  REDUCE(24),       blank,  REDUCE(24),  REDUCE(24),  REDUCE(24),  REDUCE(24),  REDUCE(24),  REDUCE(24),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(36),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(37),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,    GOTO(35),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(38),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   REDUCE(4),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(39),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   REDUCE(7),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   REDUCE(7),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(12),   SHIFT(13),   SHIFT(23),       blank,   SHIFT(16),   SHIFT(17),   SHIFT(18),   SHIFT(19),   SHIFT(20),   SHIFT(21),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(42),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,    GOTO(14),    GOTO(41),     GOTO(8),     GOTO(9),    GOTO(10),    GOTO(40),       blank,       blank,    GOTO(11),    GOTO(15),    GOTO(22),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(12),   SHIFT(13),   SHIFT(23),       blank,   SHIFT(16),   SHIFT(17),   SHIFT(18),   SHIFT(19),   SHIFT(20),   SHIFT(21),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(42),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,    GOTO(14),    GOTO(41),     GOTO(8),     GOTO(9),    GOTO(10),    GOTO(43),       blank,       blank,    GOTO(11),    GOTO(15),    GOTO(22),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(10),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(32),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,    GOTO(44),    GOTO(31),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(16),  REDUCE(16),   SHIFT(45),  REDUCE(16),  REDUCE(16),  REDUCE(16),       blank,  REDUCE(16),  REDUCE(16),  REDUCE(16),  REDUCE(16),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(16),  REDUCE(16),  REDUCE(16),  REDUCE(16),  REDUCE(16),  REDUCE(16),  REDUCE(16),  REDUCE(16),  REDUCE(16),  REDUCE(16),  REDUCE(16),  REDUCE(16),  REDUCE(16),  REDUCE(16),  REDUCE(16),  REDUCE(16),  REDUCE(16),  REDUCE(16),  REDUCE(16),  REDUCE(16),  REDUCE(16),  REDUCE(16),  REDUCE(16),  REDUCE(16),  REDUCE(16),  REDUCE(16),  REDUCE(16),  REDUCE(16),  REDUCE(16),  REDUCE(16),  REDUCE(16),  REDUCE(16),  REDUCE(16),  REDUCE(16),       blank,  REDUCE(16),  REDUCE(16),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(32),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,    GOTO(46),    GOTO(31),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(25),  REDUCE(25),  REDUCE(25),       blank,  REDUCE(25),  REDUCE(25),  REDUCE(25),  REDUCE(25),  REDUCE(25),  REDUCE(25),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(25),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(25),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(55),       blank,       blank,       blank,   SHIFT(23),       blank,   SHIFT(16),   SHIFT(17),   SHIFT(18),   SHIFT(19),   SHIFT(20),   SHIFT(21),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(49),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,    GOTO(50),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,    GOTO(53),    GOTO(22),       blank,    GOTO(47),    GOTO(48),    GOTO(51),    GOTO(52),    GOTO(56),    GOTO(58),    GOTO(54),    GOTO(57),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(32),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,    GOTO(59),    GOTO(31),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(30),       blank,       blank,       blank,  REDUCE(30),       blank,  REDUCE(30),  REDUCE(30),  REDUCE(30),  REDUCE(30),  REDUCE(30),  REDUCE(30),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(30),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(28),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(28),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   REDUCE(6),   REDUCE(6),   REDUCE(6),   REDUCE(6),       blank,   REDUCE(6),   REDUCE(6),   REDUCE(6),   REDUCE(6),   REDUCE(6),   REDUCE(6),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   REDUCE(9),   REDUCE(9),   REDUCE(9),       blank,   REDUCE(9),   REDUCE(9),   REDUCE(9),   REDUCE(9),   REDUCE(9),   REDUCE(9),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   REDUCE(9),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   REDUCE(9),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(60),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(14),  REDUCE(14),  REDUCE(14),       blank,  REDUCE(14),  REDUCE(14),  REDUCE(14),  REDUCE(14),  REDUCE(14),  REDUCE(14),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(14),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(14),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(11),  REDUCE(11),  REDUCE(11),       blank,  REDUCE(11),  REDUCE(11),  REDUCE(11),  REDUCE(11),  REDUCE(11),  REDUCE(11),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(11),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(11),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(15),  REDUCE(15),       blank,  REDUCE(15),  REDUCE(15),  REDUCE(15),       blank,  REDUCE(15),  REDUCE(15),  REDUCE(15),  REDUCE(15),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(15),  REDUCE(15),  REDUCE(15),  REDUCE(15),  REDUCE(15),  REDUCE(15),  REDUCE(15),  REDUCE(15),  REDUCE(15),  REDUCE(15),  REDUCE(15),  REDUCE(15),  REDUCE(15),  REDUCE(15),  REDUCE(15),  REDUCE(15),  REDUCE(15),  REDUCE(15),  REDUCE(15),  REDUCE(15),  REDUCE(15),  REDUCE(15),  REDUCE(15),  REDUCE(15),  REDUCE(15),  REDUCE(15),  REDUCE(15),  REDUCE(15),  REDUCE(15),  REDUCE(15),  REDUCE(15),  REDUCE(15),  REDUCE(15),  REDUCE(15),       blank,  REDUCE(15),  REDUCE(15),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(17),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(12),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(27),       blank,  REDUCE(27),  REDUCE(27),  REDUCE(27),       blank,  REDUCE(27),  REDUCE(27),  REDUCE(27),  REDUCE(27),  REDUCE(27),  REDUCE(27),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(27),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(27),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(55),       blank,       blank,       blank,   SHIFT(23),       blank,   SHIFT(16),   SHIFT(17),   SHIFT(18),   SHIFT(19),   SHIFT(20),   SHIFT(21),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(49),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,    GOTO(50),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,    GOTO(53),    GOTO(22),       blank,    GOTO(61),    GOTO(48),    GOTO(51),    GOTO(52),    GOTO(56),    GOTO(58),    GOTO(54),    GOTO(57),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(32),       blank,  REDUCE(32),  REDUCE(32),  REDUCE(32),       blank,  REDUCE(32),  REDUCE(32),  REDUCE(32),  REDUCE(32),  REDUCE(32),  REDUCE(32),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(32),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(32),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(55),       blank,       blank,       blank,   SHIFT(23),       blank,   SHIFT(16),   SHIFT(17),   SHIFT(18),   SHIFT(19),   SHIFT(20),   SHIFT(21),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,    GOTO(50),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,    GOTO(53),    GOTO(22),       blank,       blank,    GOTO(62),    GOTO(51),    GOTO(52),    GOTO(56),    GOTO(58),    GOTO(54),    GOTO(57),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(34),       blank,       blank,       blank,  REDUCE(34),       blank,  REDUCE(34),  REDUCE(34),  REDUCE(34),  REDUCE(34),  REDUCE(34),  REDUCE(34),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(34),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(35),       blank,       blank,       blank,  REDUCE(35),       blank,  REDUCE(35),  REDUCE(35),  REDUCE(35),  REDUCE(35),  REDUCE(35),  REDUCE(35),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(35),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(36),       blank,       blank,       blank,  REDUCE(36),       blank,  REDUCE(36),  REDUCE(36),  REDUCE(36),  REDUCE(36),  REDUCE(36),  REDUCE(36),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(36),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(37),       blank,       blank,       blank,  REDUCE(37),       blank,  REDUCE(37),  REDUCE(37),  REDUCE(37),  REDUCE(37),  REDUCE(37),  REDUCE(37),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(37),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(64),       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(63),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(41),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(65),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(70),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(71),       blank,       blank,       blank,       blank,   SHIFT(68),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,    GOTO(66),    GOTO(67),    GOTO(69),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(72),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(73),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(13),  REDUCE(13),  REDUCE(13),       blank,  REDUCE(13),  REDUCE(13),  REDUCE(13),  REDUCE(13),  REDUCE(13),  REDUCE(13),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(13),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(13),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(31),       blank,  REDUCE(31),  REDUCE(31),  REDUCE(31),       blank,  REDUCE(31),  REDUCE(31),  REDUCE(31),  REDUCE(31),  REDUCE(31),  REDUCE(31),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(31),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(31),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(33),       blank,       blank,       blank,  REDUCE(33),       blank,  REDUCE(33),  REDUCE(33),  REDUCE(33),  REDUCE(33),  REDUCE(33),  REDUCE(33),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(33),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(38),       blank,       blank,       blank,  REDUCE(38),       blank,  REDUCE(38),  REDUCE(38),  REDUCE(38),  REDUCE(38),  REDUCE(38),  REDUCE(38),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(38),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(43),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(43),       blank,       blank,       blank,       blank,  REDUCE(43),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(39),       blank,       blank,       blank,  REDUCE(39),       blank,  REDUCE(39),  REDUCE(39),  REDUCE(39),  REDUCE(39),  REDUCE(39),  REDUCE(39),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(39),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(77),       blank,       blank,       blank,       blank,   SHIFT(75),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,    GOTO(74),    GOTO(76),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(78),       blank,       blank,       blank,       blank,   SHIFT(79),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(45),       blank,       blank,       blank,       blank,  REDUCE(45),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(47),       blank,       blank,       blank,       blank,  REDUCE(47),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(48),       blank,       blank,       blank,       blank,  REDUCE(48),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(80),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,    GOTO(81),       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),    GOTO(82),    GOTO(83),    GOTO(84),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(29),       blank,       blank,       blank,  REDUCE(29),       blank,  REDUCE(29),  REDUCE(29),  REDUCE(29),  REDUCE(29),  REDUCE(29),  REDUCE(29),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(29),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(42),       blank,       blank,       blank,  REDUCE(42),       blank,  REDUCE(42),  REDUCE(42),  REDUCE(42),  REDUCE(42),  REDUCE(42),  REDUCE(42),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(42),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(50),       blank,       blank,       blank,  REDUCE(50),       blank,  REDUCE(50),  REDUCE(50),  REDUCE(50),  REDUCE(50),  REDUCE(50),  REDUCE(50),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(50),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,  SHIFT(137),  SHIFT(123),  SHIFT(121),       blank,       blank,       blank,  SHIFT(128),       blank,  SHIFT(141),  SHIFT(140),  SHIFT(142),  SHIFT(132),       blank,       blank,  SHIFT(133),  SHIFT(134),  SHIFT(135),  SHIFT(144),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(124),   GOTO(125),   GOTO(126),   GOTO(138),   GOTO(127),   GOTO(139),       blank,       blank,   GOTO(129),   GOTO(130),       blank,       blank,   GOTO(131),       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(136),   GOTO(143),       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),    GOTO(82),    GOTO(83),    GOTO(84),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
  REDUCE(53),  REDUCE(53),  REDUCE(53),  REDUCE(53),  REDUCE(53),  REDUCE(53),  REDUCE(53),  REDUCE(53),  REDUCE(53),  REDUCE(53),  REDUCE(53),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(53),  REDUCE(53),  REDUCE(53),  REDUCE(53),       blank,       blank,       blank,       blank,  REDUCE(53),       blank,  REDUCE(53),  REDUCE(53),  REDUCE(53),       blank,       blank,       blank,  REDUCE(53),       blank,  REDUCE(53),  REDUCE(53),  REDUCE(53),  REDUCE(53),       blank,       blank,  REDUCE(53),  REDUCE(53),  REDUCE(53),  REDUCE(53),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(53),  REDUCE(53),       blank,       blank,       blank,       blank,  REDUCE(53),  REDUCE(53),  REDUCE(53),       blank,  REDUCE(53),  REDUCE(53),  REDUCE(53),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(44),       blank,       blank,       blank,       blank,  REDUCE(44),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(70),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(71),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(145),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(49),       blank,       blank,       blank,       blank,  REDUCE(49),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(40),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(96),       blank,       blank,       blank,  REDUCE(96),  REDUCE(96),  REDUCE(96),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(158),  SHIFT(159),  SHIFT(146),  SHIFT(147),  SHIFT(148),  SHIFT(149),  SHIFT(150),  SHIFT(151),  SHIFT(152),  SHIFT(153),  SHIFT(154),  SHIFT(155),  SHIFT(156),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(157),  REDUCE(96),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(108),       blank,       blank,       blank, REDUCE(108), REDUCE(108), REDUCE(108),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(108), REDUCE(108), REDUCE(108), REDUCE(108), REDUCE(108), REDUCE(108), REDUCE(108), REDUCE(108), REDUCE(108), REDUCE(108), REDUCE(108), REDUCE(108), REDUCE(108),  SHIFT(160),  SHIFT(161),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(108), REDUCE(108),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(168),       blank,       blank, REDUCE(111),       blank,       blank,       blank, REDUCE(111), REDUCE(111), REDUCE(111),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(111), REDUCE(111), REDUCE(111), REDUCE(111), REDUCE(111), REDUCE(111), REDUCE(111), REDUCE(111), REDUCE(111), REDUCE(111), REDUCE(111), REDUCE(111), REDUCE(111), REDUCE(111), REDUCE(111),       blank,       blank,       blank,  SHIFT(162),  SHIFT(163),  SHIFT(164),  SHIFT(165),  SHIFT(166),  SHIFT(167),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(111), REDUCE(111),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(119),       blank,       blank, REDUCE(119),       blank,       blank,       blank, REDUCE(119), REDUCE(119), REDUCE(119),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(119), REDUCE(119), REDUCE(119), REDUCE(119), REDUCE(119), REDUCE(119), REDUCE(119), REDUCE(119), REDUCE(119), REDUCE(119), REDUCE(119), REDUCE(119), REDUCE(119), REDUCE(119), REDUCE(119),  SHIFT(169),  SHIFT(170),  SHIFT(171), REDUCE(119), REDUCE(119), REDUCE(119), REDUCE(119), REDUCE(119), REDUCE(119),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(119), REDUCE(119),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(123),       blank,       blank, REDUCE(123),       blank,       blank,       blank, REDUCE(123), REDUCE(123), REDUCE(123),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(123), REDUCE(123), REDUCE(123), REDUCE(123), REDUCE(123), REDUCE(123), REDUCE(123), REDUCE(123), REDUCE(123), REDUCE(123), REDUCE(123), REDUCE(123), REDUCE(123), REDUCE(123), REDUCE(123), REDUCE(123), REDUCE(123), REDUCE(123), REDUCE(123), REDUCE(123), REDUCE(123), REDUCE(123), REDUCE(123), REDUCE(123),  SHIFT(172),  SHIFT(173),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(123), REDUCE(123),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(126),       blank,       blank, REDUCE(126),       blank,       blank,       blank, REDUCE(126), REDUCE(126), REDUCE(126),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(126), REDUCE(126), REDUCE(126), REDUCE(126), REDUCE(126), REDUCE(126), REDUCE(126), REDUCE(126), REDUCE(126), REDUCE(126), REDUCE(126), REDUCE(126), REDUCE(126), REDUCE(126), REDUCE(126), REDUCE(126), REDUCE(126), REDUCE(126), REDUCE(126), REDUCE(126), REDUCE(126), REDUCE(126), REDUCE(126), REDUCE(126), REDUCE(126), REDUCE(126),  SHIFT(174),  SHIFT(175),       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(126), REDUCE(126),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(129),       blank,       blank, REDUCE(129),       blank,       blank,       blank, REDUCE(129), REDUCE(129), REDUCE(129),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(129), REDUCE(129), REDUCE(129), REDUCE(129), REDUCE(129), REDUCE(129), REDUCE(129), REDUCE(129), REDUCE(129), REDUCE(129), REDUCE(129), REDUCE(129), REDUCE(129), REDUCE(129), REDUCE(129), REDUCE(129), REDUCE(129), REDUCE(129), REDUCE(129), REDUCE(129), REDUCE(129), REDUCE(129), REDUCE(129), REDUCE(129), REDUCE(129), REDUCE(129), REDUCE(129), REDUCE(129),       blank,  SHIFT(176),  SHIFT(177),  SHIFT(178),       blank,       blank,       blank, REDUCE(129), REDUCE(129),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(182), REDUCE(133),       blank,       blank, REDUCE(133),       blank,       blank,  SHIFT(181), REDUCE(133), REDUCE(133), REDUCE(133),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(133), REDUCE(133), REDUCE(133), REDUCE(133), REDUCE(133), REDUCE(133), REDUCE(133), REDUCE(133), REDUCE(133), REDUCE(133), REDUCE(133), REDUCE(133), REDUCE(133), REDUCE(133), REDUCE(133), REDUCE(133), REDUCE(133), REDUCE(133), REDUCE(133), REDUCE(133), REDUCE(133), REDUCE(133), REDUCE(133), REDUCE(133), REDUCE(133), REDUCE(133), REDUCE(133), REDUCE(133),  SHIFT(183), REDUCE(133), REDUCE(133), REDUCE(133),  SHIFT(179),  SHIFT(180),       blank, REDUCE(133), REDUCE(133),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(184),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(185),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(186),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(187),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(188),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(189),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(190),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),   GOTO(191),    GOTO(83),    GOTO(84),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(151), REDUCE(151),   SHIFT(45),  SHIFT(194), REDUCE(151),       blank,       blank, REDUCE(151), REDUCE(151), REDUCE(151), REDUCE(151),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(151), REDUCE(151), REDUCE(151), REDUCE(151), REDUCE(151), REDUCE(151), REDUCE(151), REDUCE(151), REDUCE(151), REDUCE(151), REDUCE(151), REDUCE(151), REDUCE(151), REDUCE(151), REDUCE(151), REDUCE(151), REDUCE(151), REDUCE(151), REDUCE(151), REDUCE(151), REDUCE(151), REDUCE(151), REDUCE(151), REDUCE(151), REDUCE(151), REDUCE(151), REDUCE(151), REDUCE(151), REDUCE(151), REDUCE(151), REDUCE(151), REDUCE(151), REDUCE(151), REDUCE(151),       blank, REDUCE(151), REDUCE(151),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(192),   GOTO(193),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(152), REDUCE(152),       blank,       blank, REDUCE(152),       blank,       blank, REDUCE(152), REDUCE(152), REDUCE(152), REDUCE(152),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(152), REDUCE(152), REDUCE(152), REDUCE(152), REDUCE(152), REDUCE(152), REDUCE(152), REDUCE(152), REDUCE(152), REDUCE(152), REDUCE(152), REDUCE(152), REDUCE(152), REDUCE(152), REDUCE(152), REDUCE(152), REDUCE(152), REDUCE(152), REDUCE(152), REDUCE(152), REDUCE(152), REDUCE(152), REDUCE(152), REDUCE(152), REDUCE(152), REDUCE(152), REDUCE(152), REDUCE(152), REDUCE(152), REDUCE(152), REDUCE(152), REDUCE(152), REDUCE(152), REDUCE(152),       blank, REDUCE(152), REDUCE(152),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(194),       blank,       blank,       blank,  SHIFT(196),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(195),   GOTO(193),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(197),       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),    GOTO(82),    GOTO(83),    GOTO(84),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(198),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(199),
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(32),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(201),    GOTO(31),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(200),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(165), REDUCE(165),       blank,  SHIFT(194), REDUCE(165),       blank,       blank, REDUCE(165), REDUCE(165), REDUCE(165), REDUCE(165),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(165), REDUCE(165), REDUCE(165), REDUCE(165), REDUCE(165), REDUCE(165), REDUCE(165), REDUCE(165), REDUCE(165), REDUCE(165), REDUCE(165), REDUCE(165), REDUCE(165), REDUCE(165), REDUCE(165), REDUCE(165), REDUCE(165), REDUCE(165), REDUCE(165), REDUCE(165), REDUCE(165), REDUCE(165), REDUCE(165), REDUCE(165), REDUCE(165), REDUCE(165), REDUCE(165), REDUCE(165), REDUCE(165), REDUCE(165), REDUCE(165), REDUCE(165), REDUCE(165), REDUCE(165),       blank, REDUCE(165), REDUCE(165),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(202),   GOTO(193),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(70),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(71),       blank,       blank,       blank,       blank,  SHIFT(205),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(204),    GOTO(69),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(203),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(178), REDUCE(178),       blank,       blank, REDUCE(178),       blank,       blank, REDUCE(178), REDUCE(178), REDUCE(178), REDUCE(178),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(178), REDUCE(178), REDUCE(178), REDUCE(178), REDUCE(178), REDUCE(178), REDUCE(178), REDUCE(178), REDUCE(178), REDUCE(178), REDUCE(178), REDUCE(178), REDUCE(178), REDUCE(178), REDUCE(178), REDUCE(178), REDUCE(178), REDUCE(178), REDUCE(178), REDUCE(178), REDUCE(178), REDUCE(178), REDUCE(178), REDUCE(178), REDUCE(178), REDUCE(178), REDUCE(178), REDUCE(178), REDUCE(178), REDUCE(178), REDUCE(178), REDUCE(178), REDUCE(178), REDUCE(178),       blank, REDUCE(178), REDUCE(178),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(179), REDUCE(179),       blank,       blank, REDUCE(179),       blank,       blank, REDUCE(179), REDUCE(179), REDUCE(179), REDUCE(179),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(179), REDUCE(179), REDUCE(179), REDUCE(179), REDUCE(179), REDUCE(179), REDUCE(179), REDUCE(179), REDUCE(179), REDUCE(179), REDUCE(179), REDUCE(179), REDUCE(179), REDUCE(179), REDUCE(179), REDUCE(179), REDUCE(179), REDUCE(179), REDUCE(179), REDUCE(179), REDUCE(179), REDUCE(179), REDUCE(179), REDUCE(179), REDUCE(179), REDUCE(179), REDUCE(179), REDUCE(179), REDUCE(179), REDUCE(179), REDUCE(179), REDUCE(179), REDUCE(179), REDUCE(179),       blank, REDUCE(179), REDUCE(179),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(180), REDUCE(180),       blank,       blank, REDUCE(180),       blank,       blank, REDUCE(180), REDUCE(180), REDUCE(180), REDUCE(180),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(180), REDUCE(180), REDUCE(180), REDUCE(180), REDUCE(180), REDUCE(180), REDUCE(180), REDUCE(180), REDUCE(180), REDUCE(180), REDUCE(180), REDUCE(180), REDUCE(180), REDUCE(180), REDUCE(180), REDUCE(180), REDUCE(180), REDUCE(180), REDUCE(180), REDUCE(180), REDUCE(180), REDUCE(180), REDUCE(180), REDUCE(180), REDUCE(180), REDUCE(180), REDUCE(180), REDUCE(180), REDUCE(180), REDUCE(180), REDUCE(180), REDUCE(180), REDUCE(180), REDUCE(180),       blank, REDUCE(180), REDUCE(180),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(181), REDUCE(181),       blank,       blank, REDUCE(181),       blank,       blank, REDUCE(181), REDUCE(181), REDUCE(181), REDUCE(181),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(181), REDUCE(181), REDUCE(181), REDUCE(181), REDUCE(181), REDUCE(181), REDUCE(181), REDUCE(181), REDUCE(181), REDUCE(181), REDUCE(181), REDUCE(181), REDUCE(181), REDUCE(181), REDUCE(181), REDUCE(181), REDUCE(181), REDUCE(181), REDUCE(181), REDUCE(181), REDUCE(181), REDUCE(181), REDUCE(181), REDUCE(181), REDUCE(181), REDUCE(181), REDUCE(181), REDUCE(181), REDUCE(181), REDUCE(181), REDUCE(181), REDUCE(181), REDUCE(181), REDUCE(181),       blank, REDUCE(181), REDUCE(181),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(182), REDUCE(182),       blank,       blank, REDUCE(182),       blank,       blank, REDUCE(182), REDUCE(182), REDUCE(182), REDUCE(182),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(182), REDUCE(182), REDUCE(182), REDUCE(182), REDUCE(182), REDUCE(182), REDUCE(182), REDUCE(182), REDUCE(182), REDUCE(182), REDUCE(182), REDUCE(182), REDUCE(182), REDUCE(182), REDUCE(182), REDUCE(182), REDUCE(182), REDUCE(182), REDUCE(182), REDUCE(182), REDUCE(182), REDUCE(182), REDUCE(182), REDUCE(182), REDUCE(182), REDUCE(182), REDUCE(182), REDUCE(182), REDUCE(182), REDUCE(182), REDUCE(182), REDUCE(182), REDUCE(182), REDUCE(182),       blank, REDUCE(182), REDUCE(182),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(183), REDUCE(183),       blank,       blank, REDUCE(183),       blank,       blank, REDUCE(183), REDUCE(183), REDUCE(183), REDUCE(183),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(183), REDUCE(183), REDUCE(183), REDUCE(183), REDUCE(183), REDUCE(183), REDUCE(183), REDUCE(183), REDUCE(183), REDUCE(183), REDUCE(183), REDUCE(183), REDUCE(183), REDUCE(183), REDUCE(183), REDUCE(183), REDUCE(183), REDUCE(183), REDUCE(183), REDUCE(183), REDUCE(183), REDUCE(183), REDUCE(183), REDUCE(183), REDUCE(183), REDUCE(183), REDUCE(183), REDUCE(183), REDUCE(183), REDUCE(183), REDUCE(183), REDUCE(183), REDUCE(183), REDUCE(183),       blank, REDUCE(183), REDUCE(183),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(184), REDUCE(184),       blank,       blank, REDUCE(184),       blank,       blank, REDUCE(184), REDUCE(184), REDUCE(184), REDUCE(184),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(184), REDUCE(184), REDUCE(184), REDUCE(184), REDUCE(184), REDUCE(184), REDUCE(184), REDUCE(184), REDUCE(184), REDUCE(184), REDUCE(184), REDUCE(184), REDUCE(184), REDUCE(184), REDUCE(184), REDUCE(184), REDUCE(184), REDUCE(184), REDUCE(184), REDUCE(184), REDUCE(184), REDUCE(184), REDUCE(184), REDUCE(184), REDUCE(184), REDUCE(184), REDUCE(184), REDUCE(184), REDUCE(184), REDUCE(184), REDUCE(184), REDUCE(184), REDUCE(184), REDUCE(184),       blank, REDUCE(184), REDUCE(184),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(185), REDUCE(185),       blank,       blank, REDUCE(185),       blank,       blank, REDUCE(185), REDUCE(185), REDUCE(185), REDUCE(185),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(185), REDUCE(185), REDUCE(185), REDUCE(185), REDUCE(185), REDUCE(185), REDUCE(185), REDUCE(185), REDUCE(185), REDUCE(185), REDUCE(185), REDUCE(185), REDUCE(185), REDUCE(185), REDUCE(185), REDUCE(185), REDUCE(185), REDUCE(185), REDUCE(185), REDUCE(185), REDUCE(185), REDUCE(185), REDUCE(185), REDUCE(185), REDUCE(185), REDUCE(185), REDUCE(185), REDUCE(185), REDUCE(185), REDUCE(185), REDUCE(185), REDUCE(185), REDUCE(185), REDUCE(185),       blank, REDUCE(185), REDUCE(185),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(186), REDUCE(186),       blank,       blank, REDUCE(186),       blank,       blank, REDUCE(186), REDUCE(186), REDUCE(186), REDUCE(186),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(186), REDUCE(186), REDUCE(186), REDUCE(186), REDUCE(186), REDUCE(186), REDUCE(186), REDUCE(186), REDUCE(186), REDUCE(186), REDUCE(186), REDUCE(186), REDUCE(186), REDUCE(186), REDUCE(186), REDUCE(186), REDUCE(186), REDUCE(186), REDUCE(186), REDUCE(186), REDUCE(186), REDUCE(186), REDUCE(186), REDUCE(186), REDUCE(186), REDUCE(186), REDUCE(186), REDUCE(186), REDUCE(186), REDUCE(186), REDUCE(186), REDUCE(186), REDUCE(186), REDUCE(186),       blank, REDUCE(186), REDUCE(186),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(122),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(187), REDUCE(187),       blank,       blank, REDUCE(187),       blank,       blank, REDUCE(187), REDUCE(187), REDUCE(187), REDUCE(187),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(187), REDUCE(187), REDUCE(187), REDUCE(187), REDUCE(187), REDUCE(187), REDUCE(187), REDUCE(187), REDUCE(187), REDUCE(187), REDUCE(187), REDUCE(187), REDUCE(187), REDUCE(187), REDUCE(187), REDUCE(187), REDUCE(187), REDUCE(187), REDUCE(187), REDUCE(187), REDUCE(187), REDUCE(187), REDUCE(187), REDUCE(187), REDUCE(187), REDUCE(187), REDUCE(187), REDUCE(187), REDUCE(187), REDUCE(187), REDUCE(187), REDUCE(187), REDUCE(187), REDUCE(187),       blank, REDUCE(187), REDUCE(187),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(206),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),  REDUCE(89),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(208),       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),   GOTO(207),       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),    GOTO(82),    GOTO(83),    GOTO(84),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(32),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(201),    GOTO(31),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(209),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(210),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(189),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(189), REDUCE(189),       blank,       blank, REDUCE(189),       blank,       blank, REDUCE(189), REDUCE(189), REDUCE(189), REDUCE(189),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(189), REDUCE(189), REDUCE(189), REDUCE(189), REDUCE(189), REDUCE(189), REDUCE(189), REDUCE(189), REDUCE(189), REDUCE(189), REDUCE(189), REDUCE(189), REDUCE(189), REDUCE(189), REDUCE(189), REDUCE(189), REDUCE(189), REDUCE(189), REDUCE(189), REDUCE(189), REDUCE(189), REDUCE(189), REDUCE(189), REDUCE(189), REDUCE(189), REDUCE(189), REDUCE(189), REDUCE(189), REDUCE(189), REDUCE(189), REDUCE(189), REDUCE(189), REDUCE(189), REDUCE(189),       blank, REDUCE(189), REDUCE(189),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
  REDUCE(91),  REDUCE(91),  REDUCE(91),  REDUCE(91),  REDUCE(91),  REDUCE(91),  REDUCE(91),  REDUCE(91),  REDUCE(91),  REDUCE(91),  REDUCE(91),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(91),  REDUCE(91),  REDUCE(91),  REDUCE(91),       blank,       blank,       blank,       blank,  REDUCE(91),       blank,       blank,       blank,  REDUCE(91),  REDUCE(91),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(91),  REDUCE(91),       blank,       blank,       blank,       blank,  REDUCE(91),  REDUCE(91),  REDUCE(91),       blank,  REDUCE(91),  REDUCE(91),  REDUCE(91),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(190),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(190), REDUCE(190),       blank,       blank, REDUCE(190),       blank,       blank, REDUCE(190), REDUCE(190), REDUCE(190), REDUCE(190),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(190), REDUCE(190), REDUCE(190), REDUCE(190), REDUCE(190), REDUCE(190), REDUCE(190), REDUCE(190), REDUCE(190), REDUCE(190), REDUCE(190), REDUCE(190), REDUCE(190), REDUCE(190), REDUCE(190), REDUCE(190), REDUCE(190), REDUCE(190), REDUCE(190), REDUCE(190), REDUCE(190), REDUCE(190), REDUCE(190), REDUCE(190), REDUCE(190), REDUCE(190), REDUCE(190), REDUCE(190), REDUCE(190), REDUCE(190), REDUCE(190), REDUCE(190), REDUCE(190), REDUCE(190),       blank, REDUCE(190), REDUCE(190),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(51),       blank,       blank,       blank,  REDUCE(51),       blank,  REDUCE(51),  REDUCE(51),  REDUCE(51),  REDUCE(51),  REDUCE(51),  REDUCE(51),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(51),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,  SHIFT(137),  SHIFT(212),  SHIFT(121),       blank,       blank,       blank,  SHIFT(128),       blank,  SHIFT(141),  SHIFT(140),  SHIFT(142),  SHIFT(132),       blank,       blank,  SHIFT(133),  SHIFT(134),  SHIFT(135),  SHIFT(144),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(211),   GOTO(126),   GOTO(138),   GOTO(127),   GOTO(139),       blank,       blank,   GOTO(129),   GOTO(130),       blank,       blank,   GOTO(131),       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(136),   GOTO(143),       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),    GOTO(82),    GOTO(83),    GOTO(84),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
  REDUCE(55),  REDUCE(55),  REDUCE(55),  REDUCE(55),  REDUCE(55),  REDUCE(55),  REDUCE(55),  REDUCE(55),  REDUCE(55),  REDUCE(55),  REDUCE(55),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(55),  REDUCE(55),  REDUCE(55),  REDUCE(55),       blank,       blank,       blank,       blank,  REDUCE(55),       blank,  REDUCE(55),  REDUCE(55),  REDUCE(55),       blank,       blank,       blank,  REDUCE(55),       blank,  REDUCE(55),  REDUCE(55),  REDUCE(55),  REDUCE(55),       blank,       blank,  REDUCE(55),  REDUCE(55),  REDUCE(55),  REDUCE(55),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(55),  REDUCE(55),       blank,       blank,       blank,       blank,  REDUCE(55),  REDUCE(55),  REDUCE(55),       blank,  REDUCE(55),  REDUCE(55),  REDUCE(55),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),       blank,  REDUCE(56),  REDUCE(56),       blank,  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),       blank,  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),  REDUCE(56),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),       blank,  REDUCE(60),  REDUCE(60),       blank,  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),       blank,  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),  REDUCE(60),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(214),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(213),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(214),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(215),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,  SHIFT(137),       blank,  SHIFT(121),       blank,       blank,       blank,  SHIFT(128),       blank,  SHIFT(141),  SHIFT(140),  SHIFT(142),  SHIFT(132),       blank,       blank,  SHIFT(133),  SHIFT(134),  SHIFT(135),  SHIFT(144),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(216),   GOTO(126),   GOTO(138),   GOTO(127),   GOTO(139),       blank,       blank,   GOTO(129),   GOTO(130),       blank,       blank,   GOTO(131),       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(136),   GOTO(143),       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),    GOTO(82),    GOTO(83),    GOTO(84),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(217),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(218),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(219),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(220),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(221),   GOTO(143),       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),    GOTO(82),    GOTO(83),    GOTO(84),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(222),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
  REDUCE(59),  REDUCE(59),  REDUCE(59),  REDUCE(59),  REDUCE(59),  REDUCE(59),  REDUCE(59),  REDUCE(59),  REDUCE(59),  REDUCE(59),  REDUCE(59),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(59),  REDUCE(59),  REDUCE(59),  REDUCE(59),       blank,       blank,       blank,       blank,  REDUCE(59),       blank,  REDUCE(59),  SHIFT(223),  REDUCE(59),       blank,       blank,       blank,  REDUCE(59),       blank,  REDUCE(59),  REDUCE(59),  REDUCE(59),  REDUCE(59),       blank,       blank,  REDUCE(59),  REDUCE(59),  REDUCE(59),  REDUCE(59),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(59),  REDUCE(59),       blank,       blank,       blank,       blank,  REDUCE(59),  REDUCE(59),  REDUCE(59),       blank,  REDUCE(59),  REDUCE(59),  REDUCE(59),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,  SHIFT(137),       blank,  SHIFT(121),       blank,       blank,       blank,  SHIFT(128),       blank,  SHIFT(141),  SHIFT(140),  SHIFT(142),  SHIFT(132),       blank,       blank,  SHIFT(133),  SHIFT(134),  SHIFT(135),  SHIFT(144),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(224),   GOTO(125),   GOTO(126),   GOTO(138),   GOTO(127),   GOTO(139),       blank,       blank,   GOTO(129),   GOTO(130),       blank,       blank,   GOTO(131),       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(136),   GOTO(143),       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),    GOTO(82),    GOTO(83),    GOTO(84),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(137),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(225),   GOTO(138),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(68),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
  REDUCE(70),  REDUCE(70),  REDUCE(70),  REDUCE(70),  REDUCE(70),  REDUCE(70),  REDUCE(70),  REDUCE(70),  REDUCE(70),  REDUCE(70),  REDUCE(70),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(70),  REDUCE(70),  REDUCE(70),  REDUCE(70),       blank,       blank,       blank,       blank,  REDUCE(70),       blank,  REDUCE(70),       blank,  REDUCE(70),       blank,       blank,       blank,  REDUCE(70),       blank,  REDUCE(70),  REDUCE(70),  REDUCE(70),  REDUCE(70),       blank,       blank,  REDUCE(70),  REDUCE(70),  REDUCE(70),  REDUCE(70),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(70),  REDUCE(70),       blank,       blank,       blank,       blank,  REDUCE(70),  REDUCE(70),  REDUCE(70),       blank,  REDUCE(70),  REDUCE(70),  REDUCE(70),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(74),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(95),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(62),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(46),       blank,       blank,       blank,       blank,  REDUCE(46),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),   GOTO(226),    GOTO(83),    GOTO(84),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),   GOTO(227),    GOTO(83),    GOTO(84),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),   GOTO(228),    GOTO(83),    GOTO(84),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),   GOTO(229),    GOTO(83),    GOTO(84),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),   GOTO(230),    GOTO(83),    GOTO(84),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),   GOTO(231),    GOTO(83),    GOTO(84),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),   GOTO(232),    GOTO(83),    GOTO(84),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),   GOTO(233),    GOTO(83),    GOTO(84),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),   GOTO(234),    GOTO(83),    GOTO(84),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),   GOTO(235),    GOTO(83),    GOTO(84),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),   GOTO(236),    GOTO(83),    GOTO(84),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(237),       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),    GOTO(82),    GOTO(83),    GOTO(84),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(238),       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),    GOTO(82),    GOTO(83),    GOTO(84),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(239),       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),    GOTO(82),    GOTO(83),    GOTO(84),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),       blank,       blank,   GOTO(240),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),       blank,       blank,   GOTO(241),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),       blank,       blank,       blank,   GOTO(242),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),       blank,       blank,       blank,   GOTO(243),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),       blank,       blank,       blank,   GOTO(244),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),       blank,       blank,       blank,   GOTO(245),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),       blank,       blank,       blank,   GOTO(246),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),       blank,       blank,       blank,   GOTO(247),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),       blank,       blank,       blank,   GOTO(248),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),       blank,       blank,       blank,       blank,   GOTO(249),    GOTO(87),    GOTO(88),    GOTO(89),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),       blank,       blank,       blank,       blank,   GOTO(250),    GOTO(87),    GOTO(88),    GOTO(89),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),       blank,       blank,       blank,       blank,   GOTO(251),    GOTO(87),    GOTO(88),    GOTO(89),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),       blank,       blank,       blank,       blank,       blank,   GOTO(252),    GOTO(88),    GOTO(89),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),       blank,       blank,       blank,       blank,       blank,   GOTO(253),    GOTO(88),    GOTO(89),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(254),    GOTO(89),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(255),    GOTO(89),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(256),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(257),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(258),
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(134), REDUCE(134),       blank,       blank, REDUCE(134),       blank,       blank, REDUCE(134), REDUCE(134), REDUCE(134), REDUCE(134),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(134), REDUCE(134), REDUCE(134), REDUCE(134), REDUCE(134), REDUCE(134), REDUCE(134), REDUCE(134), REDUCE(134), REDUCE(134), REDUCE(134), REDUCE(134), REDUCE(134), REDUCE(134), REDUCE(134), REDUCE(134), REDUCE(134), REDUCE(134), REDUCE(134), REDUCE(134), REDUCE(134), REDUCE(134), REDUCE(134), REDUCE(134), REDUCE(134), REDUCE(134), REDUCE(134), REDUCE(134), REDUCE(134), REDUCE(134), REDUCE(134), REDUCE(134), REDUCE(134), REDUCE(134),       blank, REDUCE(134), REDUCE(134),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(135), REDUCE(135),       blank,       blank, REDUCE(135),       blank,       blank, REDUCE(135), REDUCE(135), REDUCE(135), REDUCE(135),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(135), REDUCE(135), REDUCE(135), REDUCE(135), REDUCE(135), REDUCE(135), REDUCE(135), REDUCE(135), REDUCE(135), REDUCE(135), REDUCE(135), REDUCE(135), REDUCE(135), REDUCE(135), REDUCE(135), REDUCE(135), REDUCE(135), REDUCE(135), REDUCE(135), REDUCE(135), REDUCE(135), REDUCE(135), REDUCE(135), REDUCE(135), REDUCE(135), REDUCE(135), REDUCE(135), REDUCE(135), REDUCE(135), REDUCE(135), REDUCE(135), REDUCE(135), REDUCE(135), REDUCE(135),       blank, REDUCE(135), REDUCE(135),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(264),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,   GOTO(259),   GOTO(261),   GOTO(262),   GOTO(263),   GOTO(116),   GOTO(120),   GOTO(260),    GOTO(83),    GOTO(84),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),   GOTO(265),    GOTO(83),    GOTO(84),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(266),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(88),  REDUCE(88),       blank,       blank,  REDUCE(88),       blank,       blank,  REDUCE(88),  REDUCE(88),  REDUCE(88),  REDUCE(88),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(88),  REDUCE(88),  REDUCE(88),  REDUCE(88),  REDUCE(88),  REDUCE(88),  REDUCE(88),  REDUCE(88),  REDUCE(88),  REDUCE(88),  REDUCE(88),  REDUCE(88),  REDUCE(88),  REDUCE(88),  REDUCE(88),  REDUCE(88),  REDUCE(88),  REDUCE(88),  REDUCE(88),  REDUCE(88),  REDUCE(88),  REDUCE(88),  REDUCE(88),  REDUCE(88),  REDUCE(88),  REDUCE(88),  REDUCE(88),  REDUCE(88),  REDUCE(88),  REDUCE(88),  REDUCE(88),  REDUCE(88),  REDUCE(88),  REDUCE(88),       blank,  REDUCE(88),  REDUCE(88),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(182), REDUCE(136),       blank,       blank, REDUCE(136),       blank,       blank,  SHIFT(181), REDUCE(136), REDUCE(136), REDUCE(136),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(136), REDUCE(136), REDUCE(136), REDUCE(136), REDUCE(136), REDUCE(136), REDUCE(136), REDUCE(136), REDUCE(136), REDUCE(136), REDUCE(136), REDUCE(136), REDUCE(136), REDUCE(136), REDUCE(136), REDUCE(136), REDUCE(136), REDUCE(136), REDUCE(136), REDUCE(136), REDUCE(136), REDUCE(136), REDUCE(136), REDUCE(136), REDUCE(136), REDUCE(136), REDUCE(136), REDUCE(136),  SHIFT(183), REDUCE(136), REDUCE(136), REDUCE(136),  SHIFT(179),  SHIFT(180),       blank, REDUCE(136), REDUCE(136),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(182), REDUCE(137),       blank,       blank, REDUCE(137),       blank,       blank,  SHIFT(181), REDUCE(137), REDUCE(137), REDUCE(137),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(137), REDUCE(137), REDUCE(137), REDUCE(137), REDUCE(137), REDUCE(137), REDUCE(137), REDUCE(137), REDUCE(137), REDUCE(137), REDUCE(137), REDUCE(137), REDUCE(137), REDUCE(137), REDUCE(137), REDUCE(137), REDUCE(137), REDUCE(137), REDUCE(137), REDUCE(137), REDUCE(137), REDUCE(137), REDUCE(137), REDUCE(137), REDUCE(137), REDUCE(137), REDUCE(137), REDUCE(137),  SHIFT(183), REDUCE(137), REDUCE(137), REDUCE(137),  SHIFT(179),  SHIFT(180),       blank, REDUCE(137), REDUCE(137),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(182), REDUCE(138),       blank,       blank, REDUCE(138),       blank,       blank,  SHIFT(181), REDUCE(138), REDUCE(138), REDUCE(138),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(138), REDUCE(138), REDUCE(138), REDUCE(138), REDUCE(138), REDUCE(138), REDUCE(138), REDUCE(138), REDUCE(138), REDUCE(138), REDUCE(138), REDUCE(138), REDUCE(138), REDUCE(138), REDUCE(138), REDUCE(138), REDUCE(138), REDUCE(138), REDUCE(138), REDUCE(138), REDUCE(138), REDUCE(138), REDUCE(138), REDUCE(138), REDUCE(138), REDUCE(138), REDUCE(138), REDUCE(138),  SHIFT(183), REDUCE(138), REDUCE(138), REDUCE(138),  SHIFT(179),  SHIFT(180),       blank, REDUCE(138), REDUCE(138),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(182), REDUCE(139),       blank,       blank, REDUCE(139),       blank,       blank,  SHIFT(181), REDUCE(139), REDUCE(139), REDUCE(139),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(139), REDUCE(139), REDUCE(139), REDUCE(139), REDUCE(139), REDUCE(139), REDUCE(139), REDUCE(139), REDUCE(139), REDUCE(139), REDUCE(139), REDUCE(139), REDUCE(139), REDUCE(139), REDUCE(139), REDUCE(139), REDUCE(139), REDUCE(139), REDUCE(139), REDUCE(139), REDUCE(139), REDUCE(139), REDUCE(139), REDUCE(139), REDUCE(139), REDUCE(139), REDUCE(139), REDUCE(139),  SHIFT(183), REDUCE(139), REDUCE(139), REDUCE(139),  SHIFT(179),  SHIFT(180),       blank, REDUCE(139), REDUCE(139),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(182), REDUCE(140),       blank,       blank, REDUCE(140),       blank,       blank,  SHIFT(181), REDUCE(140), REDUCE(140), REDUCE(140),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(140), REDUCE(140), REDUCE(140), REDUCE(140), REDUCE(140), REDUCE(140), REDUCE(140), REDUCE(140), REDUCE(140), REDUCE(140), REDUCE(140), REDUCE(140), REDUCE(140), REDUCE(140), REDUCE(140), REDUCE(140), REDUCE(140), REDUCE(140), REDUCE(140), REDUCE(140), REDUCE(140), REDUCE(140), REDUCE(140), REDUCE(140), REDUCE(140), REDUCE(140), REDUCE(140), REDUCE(140),  SHIFT(183), REDUCE(140), REDUCE(140), REDUCE(140),  SHIFT(179),  SHIFT(180),       blank, REDUCE(140), REDUCE(140),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(182), REDUCE(141),       blank,       blank, REDUCE(141),       blank,       blank,  SHIFT(181), REDUCE(141), REDUCE(141), REDUCE(141),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(141), REDUCE(141), REDUCE(141), REDUCE(141), REDUCE(141), REDUCE(141), REDUCE(141), REDUCE(141), REDUCE(141), REDUCE(141), REDUCE(141), REDUCE(141), REDUCE(141), REDUCE(141), REDUCE(141), REDUCE(141), REDUCE(141), REDUCE(141), REDUCE(141), REDUCE(141), REDUCE(141), REDUCE(141), REDUCE(141), REDUCE(141), REDUCE(141), REDUCE(141), REDUCE(141), REDUCE(141),  SHIFT(183), REDUCE(141), REDUCE(141), REDUCE(141),  SHIFT(179),  SHIFT(180),       blank, REDUCE(141), REDUCE(141),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(267),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(158),  SHIFT(159),  SHIFT(146),  SHIFT(147),  SHIFT(148),  SHIFT(149),  SHIFT(150),  SHIFT(151),  SHIFT(152),  SHIFT(153),  SHIFT(154),  SHIFT(155),  SHIFT(156),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(157),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(166), REDUCE(166),       blank,       blank, REDUCE(166),       blank,       blank, REDUCE(166), REDUCE(166), REDUCE(166), REDUCE(166),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(166), REDUCE(166), REDUCE(166), REDUCE(166), REDUCE(166), REDUCE(166), REDUCE(166), REDUCE(166), REDUCE(166), REDUCE(166), REDUCE(166), REDUCE(166), REDUCE(166), REDUCE(166), REDUCE(166), REDUCE(166), REDUCE(166), REDUCE(166), REDUCE(166), REDUCE(166), REDUCE(166), REDUCE(166), REDUCE(166), REDUCE(166), REDUCE(166), REDUCE(166), REDUCE(166), REDUCE(166), REDUCE(166), REDUCE(166), REDUCE(166), REDUCE(166), REDUCE(166), REDUCE(166),       blank, REDUCE(166), REDUCE(166),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),  SHIFT(268),       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(270),       blank,       blank,   GOTO(269),   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),    GOTO(82),    GOTO(83),    GOTO(84),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
 REDUCE(170), REDUCE(170), REDUCE(170), REDUCE(170), REDUCE(170), REDUCE(170), REDUCE(170), REDUCE(170), REDUCE(170), REDUCE(170), REDUCE(170),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(170), REDUCE(170), REDUCE(170), REDUCE(170),       blank,       blank,       blank,       blank, REDUCE(170), REDUCE(170),       blank,       blank, REDUCE(170),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(170), REDUCE(170),       blank,       blank,       blank,       blank, REDUCE(170), REDUCE(170), REDUCE(170),       blank, REDUCE(170), REDUCE(170), REDUCE(170),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(153), REDUCE(153),       blank,       blank, REDUCE(153),       blank,       blank, REDUCE(153), REDUCE(153), REDUCE(153), REDUCE(153),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(153), REDUCE(153), REDUCE(153), REDUCE(153), REDUCE(153), REDUCE(153), REDUCE(153), REDUCE(153), REDUCE(153), REDUCE(153), REDUCE(153), REDUCE(153), REDUCE(153), REDUCE(153), REDUCE(153), REDUCE(153), REDUCE(153), REDUCE(153), REDUCE(153), REDUCE(153), REDUCE(153), REDUCE(153), REDUCE(153), REDUCE(153), REDUCE(153), REDUCE(153), REDUCE(153), REDUCE(153), REDUCE(153), REDUCE(153), REDUCE(153), REDUCE(153), REDUCE(153), REDUCE(153),       blank, REDUCE(153), REDUCE(153),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(271),       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),    GOTO(82),    GOTO(83),    GOTO(84),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(156), REDUCE(156),       blank,       blank, REDUCE(156),       blank,       blank, REDUCE(156), REDUCE(156), REDUCE(156), REDUCE(156),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(156), REDUCE(156), REDUCE(156), REDUCE(156), REDUCE(156), REDUCE(156), REDUCE(156), REDUCE(156), REDUCE(156), REDUCE(156), REDUCE(156), REDUCE(156), REDUCE(156), REDUCE(156), REDUCE(156), REDUCE(156), REDUCE(156), REDUCE(156), REDUCE(156), REDUCE(156), REDUCE(156), REDUCE(156), REDUCE(156), REDUCE(156), REDUCE(156), REDUCE(156), REDUCE(156), REDUCE(156), REDUCE(156), REDUCE(156), REDUCE(156), REDUCE(156), REDUCE(156), REDUCE(156),       blank, REDUCE(156), REDUCE(156),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(182), REDUCE(157),       blank,       blank, REDUCE(157),       blank,       blank,  SHIFT(181), REDUCE(157), REDUCE(157), REDUCE(157),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(157), REDUCE(157), REDUCE(157), REDUCE(157), REDUCE(157), REDUCE(157), REDUCE(157), REDUCE(157), REDUCE(157), REDUCE(157), REDUCE(157), REDUCE(157), REDUCE(157), REDUCE(157), REDUCE(157), REDUCE(157), REDUCE(157), REDUCE(157), REDUCE(157), REDUCE(157), REDUCE(157), REDUCE(157), REDUCE(157), REDUCE(157), REDUCE(157), REDUCE(157), REDUCE(157), REDUCE(157),  SHIFT(183), REDUCE(157), REDUCE(157), REDUCE(157),  SHIFT(179),  SHIFT(180),       blank, REDUCE(157), REDUCE(157),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(182), REDUCE(158),       blank,       blank, REDUCE(158),       blank,       blank,  SHIFT(181), REDUCE(158), REDUCE(158), REDUCE(158),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(158), REDUCE(158), REDUCE(158), REDUCE(158), REDUCE(158), REDUCE(158), REDUCE(158), REDUCE(158), REDUCE(158), REDUCE(158), REDUCE(158), REDUCE(158), REDUCE(158), REDUCE(158), REDUCE(158), REDUCE(158), REDUCE(158), REDUCE(158), REDUCE(158), REDUCE(158), REDUCE(158), REDUCE(158), REDUCE(158), REDUCE(158), REDUCE(158), REDUCE(158), REDUCE(158), REDUCE(158),  SHIFT(183), REDUCE(158), REDUCE(158), REDUCE(158),  SHIFT(179),  SHIFT(180),       blank, REDUCE(158), REDUCE(158),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(163), REDUCE(163),       blank,       blank, REDUCE(163),       blank,       blank, REDUCE(163), REDUCE(163), REDUCE(163), REDUCE(163),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(163), REDUCE(163), REDUCE(163), REDUCE(163), REDUCE(163), REDUCE(163), REDUCE(163), REDUCE(163), REDUCE(163), REDUCE(163), REDUCE(163), REDUCE(163), REDUCE(163), REDUCE(163), REDUCE(163), REDUCE(163), REDUCE(163), REDUCE(163), REDUCE(163), REDUCE(163), REDUCE(163), REDUCE(163), REDUCE(163), REDUCE(163), REDUCE(163), REDUCE(163), REDUCE(163), REDUCE(163), REDUCE(163), REDUCE(163), REDUCE(163), REDUCE(163), REDUCE(163), REDUCE(163),       blank, REDUCE(163), REDUCE(163),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(164), REDUCE(164),       blank, REDUCE(164), REDUCE(164),       blank,       blank, REDUCE(164), REDUCE(164), REDUCE(164), REDUCE(164),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(164), REDUCE(164), REDUCE(164), REDUCE(164), REDUCE(164), REDUCE(164), REDUCE(164), REDUCE(164), REDUCE(164), REDUCE(164), REDUCE(164), REDUCE(164), REDUCE(164), REDUCE(164), REDUCE(164), REDUCE(164), REDUCE(164), REDUCE(164), REDUCE(164), REDUCE(164), REDUCE(164), REDUCE(164), REDUCE(164), REDUCE(164), REDUCE(164), REDUCE(164), REDUCE(164), REDUCE(164), REDUCE(164), REDUCE(164), REDUCE(164), REDUCE(164), REDUCE(164), REDUCE(164),       blank, REDUCE(164), REDUCE(164),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(167), REDUCE(167),       blank,       blank, REDUCE(167),       blank,       blank, REDUCE(167), REDUCE(167), REDUCE(167), REDUCE(167),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(167), REDUCE(167), REDUCE(167), REDUCE(167), REDUCE(167), REDUCE(167), REDUCE(167), REDUCE(167), REDUCE(167), REDUCE(167), REDUCE(167), REDUCE(167), REDUCE(167), REDUCE(167), REDUCE(167), REDUCE(167), REDUCE(167), REDUCE(167), REDUCE(167), REDUCE(167), REDUCE(167), REDUCE(167), REDUCE(167), REDUCE(167), REDUCE(167), REDUCE(167), REDUCE(167), REDUCE(167), REDUCE(167), REDUCE(167), REDUCE(167), REDUCE(167), REDUCE(167), REDUCE(167),       blank, REDUCE(167), REDUCE(167),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,  SHIFT(137),       blank,  SHIFT(121),       blank,       blank,       blank,  SHIFT(128),       blank,  SHIFT(141),  SHIFT(140),  SHIFT(142),  SHIFT(132),       blank,       blank,  SHIFT(133),  SHIFT(134),  SHIFT(135),  SHIFT(144),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(272),   GOTO(126),   GOTO(138),   GOTO(127),   GOTO(139),       blank,       blank,   GOTO(129),   GOTO(130),       blank,       blank,   GOTO(131),       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(136),   GOTO(143),       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),    GOTO(82),    GOTO(83),    GOTO(84),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(273),       blank,       blank,       blank,       blank,   SHIFT(79),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
 REDUCE(177), REDUCE(177), REDUCE(177), REDUCE(177), REDUCE(177), REDUCE(177), REDUCE(177), REDUCE(177), REDUCE(177), REDUCE(177), REDUCE(177),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(177), REDUCE(177), REDUCE(177), REDUCE(177),       blank,       blank,       blank,       blank, REDUCE(177),       blank, REDUCE(177),       blank, REDUCE(177),       blank,       blank,       blank, REDUCE(177),       blank, REDUCE(177), REDUCE(177), REDUCE(177), REDUCE(177),       blank,       blank, REDUCE(177), REDUCE(177), REDUCE(177), REDUCE(177),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(177), REDUCE(177),       blank,       blank,       blank,       blank, REDUCE(177), REDUCE(177), REDUCE(177),       blank, REDUCE(177), REDUCE(177), REDUCE(177),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(188),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(188), REDUCE(188),       blank,       blank, REDUCE(188),       blank,       blank, REDUCE(188), REDUCE(188), REDUCE(188), REDUCE(188),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(188), REDUCE(188), REDUCE(188), REDUCE(188), REDUCE(188), REDUCE(188), REDUCE(188), REDUCE(188), REDUCE(188), REDUCE(188), REDUCE(188), REDUCE(188), REDUCE(188), REDUCE(188), REDUCE(188), REDUCE(188), REDUCE(188), REDUCE(188), REDUCE(188), REDUCE(188), REDUCE(188), REDUCE(188), REDUCE(188), REDUCE(188), REDUCE(188), REDUCE(188), REDUCE(188), REDUCE(188), REDUCE(188), REDUCE(188), REDUCE(188), REDUCE(188), REDUCE(188), REDUCE(188),       blank, REDUCE(188), REDUCE(188),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(90),  SHIFT(274),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(93),  REDUCE(93),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(155),       blank,       blank,       blank, REDUCE(155),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(175),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(175),       blank,       blank,       blank,       blank, REDUCE(175),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
  REDUCE(54),  REDUCE(54),  REDUCE(54),  REDUCE(54),  REDUCE(54),  REDUCE(54),  REDUCE(54),  REDUCE(54),  REDUCE(54),  REDUCE(54),  REDUCE(54),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(54),  REDUCE(54),  REDUCE(54),  REDUCE(54),       blank,       blank,       blank,       blank,  REDUCE(54),       blank,  REDUCE(54),  REDUCE(54),  REDUCE(54),       blank,       blank,       blank,  REDUCE(54),       blank,  REDUCE(54),  REDUCE(54),  REDUCE(54),  REDUCE(54),       blank,       blank,  REDUCE(54),  REDUCE(54),  REDUCE(54),  REDUCE(54),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(54),  REDUCE(54),       blank,       blank,       blank,       blank,  REDUCE(54),  REDUCE(54),  REDUCE(54),       blank,  REDUCE(54),  REDUCE(54),  REDUCE(54),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(52),       blank,       blank,       blank,  REDUCE(52),       blank,  REDUCE(52),  REDUCE(52),  REDUCE(52),  REDUCE(52),  REDUCE(52),  REDUCE(52),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(52),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,  SHIFT(137),       blank,  SHIFT(121),       blank,       blank,       blank,  SHIFT(128),       blank,  SHIFT(141),  SHIFT(140),  SHIFT(142),  SHIFT(132),       blank,       blank,  SHIFT(133),  SHIFT(134),  SHIFT(135),  SHIFT(144),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(276),   GOTO(126),   GOTO(138),   GOTO(127),   GOTO(139),       blank,   GOTO(275),   GOTO(129),   GOTO(130),       blank,       blank,   GOTO(131),       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(136),   GOTO(143),       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),    GOTO(82),    GOTO(83),    GOTO(84),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(277),       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),    GOTO(82),    GOTO(83),    GOTO(84),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,  SHIFT(137),       blank,  SHIFT(121),       blank,       blank,       blank,  SHIFT(128),       blank,  SHIFT(141),  SHIFT(140),  SHIFT(142),  SHIFT(132),       blank,       blank,  SHIFT(133),  SHIFT(134),  SHIFT(135),  SHIFT(144),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(278),   GOTO(126),   GOTO(138),   GOTO(127),   GOTO(139),       blank,       blank,   GOTO(129),   GOTO(130),       blank,       blank,   GOTO(131),       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(136),   GOTO(143),       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),    GOTO(82),    GOTO(83),    GOTO(84),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(279),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(282),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(280),   GOTO(281),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(283),       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(284),       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),    GOTO(82),    GOTO(83),    GOTO(84),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),       blank,  REDUCE(84),  REDUCE(84),       blank,  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),       blank,  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),  REDUCE(84),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),       blank,  REDUCE(85),  REDUCE(85),       blank,  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),       blank,  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),  REDUCE(85),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(285),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),       blank,  REDUCE(87),  REDUCE(87),       blank,  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),       blank,  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),  REDUCE(87),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),       blank,  REDUCE(57),  REDUCE(57),       blank,  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),  REDUCE(57),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,  SHIFT(137),  SHIFT(286),  SHIFT(121),       blank,       blank,       blank,  SHIFT(128),       blank,  SHIFT(141),  SHIFT(140),  SHIFT(142),  SHIFT(132),       blank,       blank,  SHIFT(133),  SHIFT(134),  SHIFT(135),  SHIFT(144),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(211),   GOTO(126),   GOTO(138),   GOTO(127),   GOTO(139),       blank,       blank,   GOTO(129),   GOTO(130),       blank,       blank,   GOTO(131),       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(136),   GOTO(143),       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),    GOTO(82),    GOTO(83),    GOTO(84),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(288),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(287),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(97),       blank,       blank,       blank,  REDUCE(97),  REDUCE(97),  REDUCE(97),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(158),  SHIFT(159),  SHIFT(146),  SHIFT(147),  SHIFT(148),  SHIFT(149),  SHIFT(150),  SHIFT(151),  SHIFT(152),  SHIFT(153),  SHIFT(154),  SHIFT(155),  SHIFT(156),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(157),  REDUCE(97),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(98),       blank,       blank,       blank,  REDUCE(98),  REDUCE(98),  REDUCE(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(158),  SHIFT(159),  SHIFT(146),  SHIFT(147),  SHIFT(148),  SHIFT(149),  SHIFT(150),  SHIFT(151),  SHIFT(152),  SHIFT(153),  SHIFT(154),  SHIFT(155),  SHIFT(156),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(157),  REDUCE(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(99),       blank,       blank,       blank,  REDUCE(99),  REDUCE(99),  REDUCE(99),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(158),  SHIFT(159),  SHIFT(146),  SHIFT(147),  SHIFT(148),  SHIFT(149),  SHIFT(150),  SHIFT(151),  SHIFT(152),  SHIFT(153),  SHIFT(154),  SHIFT(155),  SHIFT(156),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(157),  REDUCE(99),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(100),       blank,       blank,       blank, REDUCE(100), REDUCE(100), REDUCE(100),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(158),  SHIFT(159),  SHIFT(146),  SHIFT(147),  SHIFT(148),  SHIFT(149),  SHIFT(150),  SHIFT(151),  SHIFT(152),  SHIFT(153),  SHIFT(154),  SHIFT(155),  SHIFT(156),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(157), REDUCE(100),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(101),       blank,       blank,       blank, REDUCE(101), REDUCE(101), REDUCE(101),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(158),  SHIFT(159),  SHIFT(146),  SHIFT(147),  SHIFT(148),  SHIFT(149),  SHIFT(150),  SHIFT(151),  SHIFT(152),  SHIFT(153),  SHIFT(154),  SHIFT(155),  SHIFT(156),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(157), REDUCE(101),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(102),       blank,       blank,       blank, REDUCE(102), REDUCE(102), REDUCE(102),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(158),  SHIFT(159),  SHIFT(146),  SHIFT(147),  SHIFT(148),  SHIFT(149),  SHIFT(150),  SHIFT(151),  SHIFT(152),  SHIFT(153),  SHIFT(154),  SHIFT(155),  SHIFT(156),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(157), REDUCE(102),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(103),       blank,       blank,       blank, REDUCE(103), REDUCE(103), REDUCE(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(158),  SHIFT(159),  SHIFT(146),  SHIFT(147),  SHIFT(148),  SHIFT(149),  SHIFT(150),  SHIFT(151),  SHIFT(152),  SHIFT(153),  SHIFT(154),  SHIFT(155),  SHIFT(156),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(157), REDUCE(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(104),       blank,       blank,       blank, REDUCE(104), REDUCE(104), REDUCE(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(158),  SHIFT(159),  SHIFT(146),  SHIFT(147),  SHIFT(148),  SHIFT(149),  SHIFT(150),  SHIFT(151),  SHIFT(152),  SHIFT(153),  SHIFT(154),  SHIFT(155),  SHIFT(156),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(157), REDUCE(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(105),       blank,       blank,       blank, REDUCE(105), REDUCE(105), REDUCE(105),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(158),  SHIFT(159),  SHIFT(146),  SHIFT(147),  SHIFT(148),  SHIFT(149),  SHIFT(150),  SHIFT(151),  SHIFT(152),  SHIFT(153),  SHIFT(154),  SHIFT(155),  SHIFT(156),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(157), REDUCE(105),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(106),       blank,       blank,       blank, REDUCE(106), REDUCE(106), REDUCE(106),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(158),  SHIFT(159),  SHIFT(146),  SHIFT(147),  SHIFT(148),  SHIFT(149),  SHIFT(150),  SHIFT(151),  SHIFT(152),  SHIFT(153),  SHIFT(154),  SHIFT(155),  SHIFT(156),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(157), REDUCE(106),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(107),       blank,       blank,       blank, REDUCE(107), REDUCE(107), REDUCE(107),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(158),  SHIFT(159),  SHIFT(146),  SHIFT(147),  SHIFT(148),  SHIFT(149),  SHIFT(150),  SHIFT(151),  SHIFT(152),  SHIFT(153),  SHIFT(154),  SHIFT(155),  SHIFT(156),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(157), REDUCE(107),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(289),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(161),       blank,       blank,       blank, REDUCE(161), REDUCE(161), REDUCE(161),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(161), REDUCE(161), REDUCE(161), REDUCE(161), REDUCE(161), REDUCE(161), REDUCE(161), REDUCE(161), REDUCE(161), REDUCE(161), REDUCE(161), REDUCE(161), REDUCE(161),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(161), REDUCE(161),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(162),       blank,       blank,       blank, REDUCE(162), REDUCE(162), REDUCE(162),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(162), REDUCE(162), REDUCE(162), REDUCE(162), REDUCE(162), REDUCE(162), REDUCE(162), REDUCE(162), REDUCE(162), REDUCE(162), REDUCE(162), REDUCE(162), REDUCE(162),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(162), REDUCE(162),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(168),       blank,       blank, REDUCE(109),       blank,       blank,       blank, REDUCE(109), REDUCE(109), REDUCE(109),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(109), REDUCE(109), REDUCE(109), REDUCE(109), REDUCE(109), REDUCE(109), REDUCE(109), REDUCE(109), REDUCE(109), REDUCE(109), REDUCE(109), REDUCE(109), REDUCE(109), REDUCE(109), REDUCE(109),       blank,       blank,       blank,  SHIFT(162),  SHIFT(163),  SHIFT(164),  SHIFT(165),  SHIFT(166),  SHIFT(167),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(109), REDUCE(109),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(168),       blank,       blank, REDUCE(110),       blank,       blank,       blank, REDUCE(110), REDUCE(110), REDUCE(110),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(110), REDUCE(110), REDUCE(110), REDUCE(110), REDUCE(110), REDUCE(110), REDUCE(110), REDUCE(110), REDUCE(110), REDUCE(110), REDUCE(110), REDUCE(110), REDUCE(110), REDUCE(110), REDUCE(110),       blank,       blank,       blank,  SHIFT(162),  SHIFT(163),  SHIFT(164),  SHIFT(165),  SHIFT(166),  SHIFT(167),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(110), REDUCE(110),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(112),       blank,       blank, REDUCE(112),       blank,       blank,       blank, REDUCE(112), REDUCE(112), REDUCE(112),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(112), REDUCE(112), REDUCE(112), REDUCE(112), REDUCE(112), REDUCE(112), REDUCE(112), REDUCE(112), REDUCE(112), REDUCE(112), REDUCE(112), REDUCE(112), REDUCE(112), REDUCE(112), REDUCE(112),  SHIFT(169),  SHIFT(170),  SHIFT(171), REDUCE(112), REDUCE(112), REDUCE(112), REDUCE(112), REDUCE(112), REDUCE(112),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(112), REDUCE(112),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(113),       blank,       blank, REDUCE(113),       blank,       blank,       blank, REDUCE(113), REDUCE(113), REDUCE(113),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(113), REDUCE(113), REDUCE(113), REDUCE(113), REDUCE(113), REDUCE(113), REDUCE(113), REDUCE(113), REDUCE(113), REDUCE(113), REDUCE(113), REDUCE(113), REDUCE(113), REDUCE(113), REDUCE(113),  SHIFT(169),  SHIFT(170),  SHIFT(171), REDUCE(113), REDUCE(113), REDUCE(113), REDUCE(113), REDUCE(113), REDUCE(113),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(113), REDUCE(113),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(114),       blank,       blank, REDUCE(114),       blank,       blank,       blank, REDUCE(114), REDUCE(114), REDUCE(114),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(114), REDUCE(114), REDUCE(114), REDUCE(114), REDUCE(114), REDUCE(114), REDUCE(114), REDUCE(114), REDUCE(114), REDUCE(114), REDUCE(114), REDUCE(114), REDUCE(114), REDUCE(114), REDUCE(114),  SHIFT(169),  SHIFT(170),  SHIFT(171), REDUCE(114), REDUCE(114), REDUCE(114), REDUCE(114), REDUCE(114), REDUCE(114),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(114), REDUCE(114),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(115),       blank,       blank, REDUCE(115),       blank,       blank,       blank, REDUCE(115), REDUCE(115), REDUCE(115),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(115), REDUCE(115), REDUCE(115), REDUCE(115), REDUCE(115), REDUCE(115), REDUCE(115), REDUCE(115), REDUCE(115), REDUCE(115), REDUCE(115), REDUCE(115), REDUCE(115), REDUCE(115), REDUCE(115),  SHIFT(169),  SHIFT(170),  SHIFT(171), REDUCE(115), REDUCE(115), REDUCE(115), REDUCE(115), REDUCE(115), REDUCE(115),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(115), REDUCE(115),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(116),       blank,       blank, REDUCE(116),       blank,       blank,       blank, REDUCE(116), REDUCE(116), REDUCE(116),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(116), REDUCE(116), REDUCE(116), REDUCE(116), REDUCE(116), REDUCE(116), REDUCE(116), REDUCE(116), REDUCE(116), REDUCE(116), REDUCE(116), REDUCE(116), REDUCE(116), REDUCE(116), REDUCE(116),  SHIFT(169),  SHIFT(170),  SHIFT(171), REDUCE(116), REDUCE(116), REDUCE(116), REDUCE(116), REDUCE(116), REDUCE(116),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(116), REDUCE(116),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(117),       blank,       blank, REDUCE(117),       blank,       blank,       blank, REDUCE(117), REDUCE(117), REDUCE(117),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(117), REDUCE(117), REDUCE(117), REDUCE(117), REDUCE(117), REDUCE(117), REDUCE(117), REDUCE(117), REDUCE(117), REDUCE(117), REDUCE(117), REDUCE(117), REDUCE(117), REDUCE(117), REDUCE(117),  SHIFT(169),  SHIFT(170),  SHIFT(171), REDUCE(117), REDUCE(117), REDUCE(117), REDUCE(117), REDUCE(117), REDUCE(117),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(117), REDUCE(117),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(118),       blank,       blank, REDUCE(118),       blank,       blank,       blank, REDUCE(118), REDUCE(118), REDUCE(118),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(118), REDUCE(118), REDUCE(118), REDUCE(118), REDUCE(118), REDUCE(118), REDUCE(118), REDUCE(118), REDUCE(118), REDUCE(118), REDUCE(118), REDUCE(118), REDUCE(118), REDUCE(118), REDUCE(118),  SHIFT(169),  SHIFT(170),  SHIFT(171), REDUCE(118), REDUCE(118), REDUCE(118), REDUCE(118), REDUCE(118), REDUCE(118),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(118), REDUCE(118),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(120),       blank,       blank, REDUCE(120),       blank,       blank,       blank, REDUCE(120), REDUCE(120), REDUCE(120),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(120), REDUCE(120), REDUCE(120), REDUCE(120), REDUCE(120), REDUCE(120), REDUCE(120), REDUCE(120), REDUCE(120), REDUCE(120), REDUCE(120), REDUCE(120), REDUCE(120), REDUCE(120), REDUCE(120), REDUCE(120), REDUCE(120), REDUCE(120), REDUCE(120), REDUCE(120), REDUCE(120), REDUCE(120), REDUCE(120), REDUCE(120),  SHIFT(172),  SHIFT(173),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(120), REDUCE(120),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(121),       blank,       blank, REDUCE(121),       blank,       blank,       blank, REDUCE(121), REDUCE(121), REDUCE(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(121), REDUCE(121), REDUCE(121), REDUCE(121), REDUCE(121), REDUCE(121), REDUCE(121), REDUCE(121), REDUCE(121), REDUCE(121), REDUCE(121), REDUCE(121), REDUCE(121), REDUCE(121), REDUCE(121), REDUCE(121), REDUCE(121), REDUCE(121), REDUCE(121), REDUCE(121), REDUCE(121), REDUCE(121), REDUCE(121), REDUCE(121),  SHIFT(172),  SHIFT(173),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(121), REDUCE(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(122),       blank,       blank, REDUCE(122),       blank,       blank,       blank, REDUCE(122), REDUCE(122), REDUCE(122),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(122), REDUCE(122), REDUCE(122), REDUCE(122), REDUCE(122), REDUCE(122), REDUCE(122), REDUCE(122), REDUCE(122), REDUCE(122), REDUCE(122), REDUCE(122), REDUCE(122), REDUCE(122), REDUCE(122), REDUCE(122), REDUCE(122), REDUCE(122), REDUCE(122), REDUCE(122), REDUCE(122), REDUCE(122), REDUCE(122), REDUCE(122),  SHIFT(172),  SHIFT(173),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(122), REDUCE(122),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(124),       blank,       blank, REDUCE(124),       blank,       blank,       blank, REDUCE(124), REDUCE(124), REDUCE(124),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(124), REDUCE(124), REDUCE(124), REDUCE(124), REDUCE(124), REDUCE(124), REDUCE(124), REDUCE(124), REDUCE(124), REDUCE(124), REDUCE(124), REDUCE(124), REDUCE(124), REDUCE(124), REDUCE(124), REDUCE(124), REDUCE(124), REDUCE(124), REDUCE(124), REDUCE(124), REDUCE(124), REDUCE(124), REDUCE(124), REDUCE(124), REDUCE(124), REDUCE(124),  SHIFT(174),  SHIFT(175),       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(124), REDUCE(124),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(125),       blank,       blank, REDUCE(125),       blank,       blank,       blank, REDUCE(125), REDUCE(125), REDUCE(125),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(125), REDUCE(125), REDUCE(125), REDUCE(125), REDUCE(125), REDUCE(125), REDUCE(125), REDUCE(125), REDUCE(125), REDUCE(125), REDUCE(125), REDUCE(125), REDUCE(125), REDUCE(125), REDUCE(125), REDUCE(125), REDUCE(125), REDUCE(125), REDUCE(125), REDUCE(125), REDUCE(125), REDUCE(125), REDUCE(125), REDUCE(125), REDUCE(125), REDUCE(125),  SHIFT(174),  SHIFT(175),       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(125), REDUCE(125),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(127),       blank,       blank, REDUCE(127),       blank,       blank,       blank, REDUCE(127), REDUCE(127), REDUCE(127),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(127), REDUCE(127), REDUCE(127), REDUCE(127), REDUCE(127), REDUCE(127), REDUCE(127), REDUCE(127), REDUCE(127), REDUCE(127), REDUCE(127), REDUCE(127), REDUCE(127), REDUCE(127), REDUCE(127), REDUCE(127), REDUCE(127), REDUCE(127), REDUCE(127), REDUCE(127), REDUCE(127), REDUCE(127), REDUCE(127), REDUCE(127), REDUCE(127), REDUCE(127), REDUCE(127), REDUCE(127),       blank,  SHIFT(176),  SHIFT(177),  SHIFT(178),       blank,       blank,       blank, REDUCE(127), REDUCE(127),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(128),       blank,       blank, REDUCE(128),       blank,       blank,       blank, REDUCE(128), REDUCE(128), REDUCE(128),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(128), REDUCE(128), REDUCE(128), REDUCE(128), REDUCE(128), REDUCE(128), REDUCE(128), REDUCE(128), REDUCE(128), REDUCE(128), REDUCE(128), REDUCE(128), REDUCE(128), REDUCE(128), REDUCE(128), REDUCE(128), REDUCE(128), REDUCE(128), REDUCE(128), REDUCE(128), REDUCE(128), REDUCE(128), REDUCE(128), REDUCE(128), REDUCE(128), REDUCE(128), REDUCE(128), REDUCE(128),       blank,  SHIFT(176),  SHIFT(177),  SHIFT(178),       blank,       blank,       blank, REDUCE(128), REDUCE(128),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(182), REDUCE(130),       blank,       blank, REDUCE(130),       blank,       blank,  SHIFT(181), REDUCE(130), REDUCE(130), REDUCE(130),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(130), REDUCE(130), REDUCE(130), REDUCE(130), REDUCE(130), REDUCE(130), REDUCE(130), REDUCE(130), REDUCE(130), REDUCE(130), REDUCE(130), REDUCE(130), REDUCE(130), REDUCE(130), REDUCE(130), REDUCE(130), REDUCE(130), REDUCE(130), REDUCE(130), REDUCE(130), REDUCE(130), REDUCE(130), REDUCE(130), REDUCE(130), REDUCE(130), REDUCE(130), REDUCE(130), REDUCE(130),  SHIFT(183), REDUCE(130), REDUCE(130), REDUCE(130),  SHIFT(179),  SHIFT(180),       blank, REDUCE(130), REDUCE(130),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(182), REDUCE(131),       blank,       blank, REDUCE(131),       blank,       blank,  SHIFT(181), REDUCE(131), REDUCE(131), REDUCE(131),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(131), REDUCE(131), REDUCE(131), REDUCE(131), REDUCE(131), REDUCE(131), REDUCE(131), REDUCE(131), REDUCE(131), REDUCE(131), REDUCE(131), REDUCE(131), REDUCE(131), REDUCE(131), REDUCE(131), REDUCE(131), REDUCE(131), REDUCE(131), REDUCE(131), REDUCE(131), REDUCE(131), REDUCE(131), REDUCE(131), REDUCE(131), REDUCE(131), REDUCE(131), REDUCE(131), REDUCE(131),  SHIFT(183), REDUCE(131), REDUCE(131), REDUCE(131),  SHIFT(179),  SHIFT(180),       blank, REDUCE(131), REDUCE(131),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(182), REDUCE(132),       blank,       blank, REDUCE(132),       blank,       blank,  SHIFT(181), REDUCE(132), REDUCE(132), REDUCE(132),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(132), REDUCE(132), REDUCE(132), REDUCE(132), REDUCE(132), REDUCE(132), REDUCE(132), REDUCE(132), REDUCE(132), REDUCE(132), REDUCE(132), REDUCE(132), REDUCE(132), REDUCE(132), REDUCE(132), REDUCE(132), REDUCE(132), REDUCE(132), REDUCE(132), REDUCE(132), REDUCE(132), REDUCE(132), REDUCE(132), REDUCE(132), REDUCE(132), REDUCE(132), REDUCE(132), REDUCE(132),  SHIFT(183), REDUCE(132), REDUCE(132), REDUCE(132),  SHIFT(179),  SHIFT(180),       blank, REDUCE(132), REDUCE(132),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(290),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(143),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(158),  SHIFT(159),  SHIFT(146),  SHIFT(147),  SHIFT(148),  SHIFT(149),  SHIFT(150),  SHIFT(151),  SHIFT(152),  SHIFT(153),  SHIFT(154),  SHIFT(155),  SHIFT(156),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(157),  SHIFT(291),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(144),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121), REDUCE(145),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),   GOTO(292),    GOTO(83),    GOTO(84),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(264),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,   GOTO(293),   GOTO(116),   GOTO(120),   GOTO(294),    GOTO(83),    GOTO(84),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
 REDUCE(149), REDUCE(149), REDUCE(149), REDUCE(149), REDUCE(149), REDUCE(149), REDUCE(149), REDUCE(149), REDUCE(149), REDUCE(149), REDUCE(149),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(149), REDUCE(149), REDUCE(149), REDUCE(149),       blank,       blank,       blank,       blank,  SHIFT(210),       blank,       blank,       blank, REDUCE(149), REDUCE(149),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(149), REDUCE(149),       blank,       blank,       blank,       blank, REDUCE(149), REDUCE(149), REDUCE(149),       blank, REDUCE(149), REDUCE(149), REDUCE(149),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(159), REDUCE(159),       blank,       blank, REDUCE(159),       blank,       blank, REDUCE(159), REDUCE(159), REDUCE(159), REDUCE(159),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(158),  SHIFT(159),  SHIFT(146),  SHIFT(147),  SHIFT(148),  SHIFT(149),  SHIFT(150),  SHIFT(151),  SHIFT(152),  SHIFT(153),  SHIFT(154),  SHIFT(155),  SHIFT(156), REDUCE(159), REDUCE(159), REDUCE(159), REDUCE(159), REDUCE(159), REDUCE(159), REDUCE(159), REDUCE(159), REDUCE(159), REDUCE(159), REDUCE(159), REDUCE(159), REDUCE(159), REDUCE(159), REDUCE(159), REDUCE(159), REDUCE(159), REDUCE(159), REDUCE(159), REDUCE(159), REDUCE(159),       blank,  SHIFT(157), REDUCE(159),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(173), REDUCE(173),       blank, REDUCE(173), REDUCE(173),       blank,       blank, REDUCE(173), REDUCE(173), REDUCE(173), REDUCE(173),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(173), REDUCE(173), REDUCE(173), REDUCE(173), REDUCE(173), REDUCE(173), REDUCE(173), REDUCE(173), REDUCE(173), REDUCE(173), REDUCE(173), REDUCE(173), REDUCE(173), REDUCE(173), REDUCE(173), REDUCE(173), REDUCE(173), REDUCE(173), REDUCE(173), REDUCE(173), REDUCE(173), REDUCE(173), REDUCE(173), REDUCE(173), REDUCE(173), REDUCE(173), REDUCE(173), REDUCE(173), REDUCE(173), REDUCE(173), REDUCE(173), REDUCE(173), REDUCE(173), REDUCE(173),       blank, REDUCE(173), REDUCE(173),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(150), REDUCE(150),       blank,       blank, REDUCE(150),       blank,       blank, REDUCE(150), REDUCE(150), REDUCE(150), REDUCE(150),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(150), REDUCE(150), REDUCE(150), REDUCE(150), REDUCE(150), REDUCE(150), REDUCE(150), REDUCE(150), REDUCE(150), REDUCE(150), REDUCE(150), REDUCE(150), REDUCE(150), REDUCE(150), REDUCE(150), REDUCE(150), REDUCE(150), REDUCE(150), REDUCE(150), REDUCE(150), REDUCE(150), REDUCE(150), REDUCE(150), REDUCE(150), REDUCE(150), REDUCE(150), REDUCE(150), REDUCE(150), REDUCE(150), REDUCE(150), REDUCE(150), REDUCE(150), REDUCE(150), REDUCE(150),       blank, REDUCE(150), REDUCE(150),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(168), REDUCE(168),       blank,       blank, REDUCE(168),       blank,       blank, REDUCE(168), REDUCE(168), REDUCE(168), REDUCE(168),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(168), REDUCE(168), REDUCE(168), REDUCE(168), REDUCE(168), REDUCE(168), REDUCE(168), REDUCE(168), REDUCE(168), REDUCE(168), REDUCE(168), REDUCE(168), REDUCE(168), REDUCE(168), REDUCE(168), REDUCE(168), REDUCE(168), REDUCE(168), REDUCE(168), REDUCE(168), REDUCE(168), REDUCE(168), REDUCE(168), REDUCE(168), REDUCE(168), REDUCE(168), REDUCE(168), REDUCE(168), REDUCE(168), REDUCE(168), REDUCE(168), REDUCE(168), REDUCE(168), REDUCE(168),       blank, REDUCE(168), REDUCE(168),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(296),       blank,       blank,       blank,       blank,  SHIFT(295),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(172),       blank,       blank,       blank,       blank, REDUCE(172),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(297),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(174), REDUCE(174),       blank,       blank, REDUCE(174),       blank,       blank, REDUCE(174), REDUCE(174), REDUCE(174), REDUCE(174),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(174), REDUCE(174), REDUCE(174), REDUCE(174), REDUCE(174), REDUCE(174), REDUCE(174), REDUCE(174), REDUCE(174), REDUCE(174), REDUCE(174), REDUCE(174), REDUCE(174), REDUCE(174), REDUCE(174), REDUCE(174), REDUCE(174), REDUCE(174), REDUCE(174), REDUCE(174), REDUCE(174), REDUCE(174), REDUCE(174), REDUCE(174), REDUCE(174), REDUCE(174), REDUCE(174), REDUCE(174), REDUCE(174), REDUCE(174), REDUCE(174), REDUCE(174), REDUCE(174), REDUCE(174),       blank, REDUCE(174), REDUCE(174),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
 REDUCE(176), REDUCE(176), REDUCE(176), REDUCE(176), REDUCE(176), REDUCE(176), REDUCE(176), REDUCE(176), REDUCE(176), REDUCE(176), REDUCE(176),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(176), REDUCE(176), REDUCE(176), REDUCE(176),       blank,       blank,       blank,       blank, REDUCE(176),       blank, REDUCE(176),       blank, REDUCE(176),       blank,       blank,       blank, REDUCE(176),       blank, REDUCE(176), REDUCE(176), REDUCE(176), REDUCE(176),       blank,       blank, REDUCE(176), REDUCE(176), REDUCE(176), REDUCE(176),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(176), REDUCE(176),       blank,       blank,       blank,       blank, REDUCE(176), REDUCE(176), REDUCE(176),       blank, REDUCE(176), REDUCE(176), REDUCE(176),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(298),       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),    GOTO(82),    GOTO(83),    GOTO(84),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),       blank,  REDUCE(64),  REDUCE(64),       blank,  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),       blank,  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),  REDUCE(64),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),       blank,  REDUCE(65),  REDUCE(65),       blank,  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  SHIFT(299),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),       blank,  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),  REDUCE(65),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(300),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),       blank,  REDUCE(67),  REDUCE(67),       blank,  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),       blank,  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),  REDUCE(67),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(214),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(301),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(302),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(303),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(73),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(304),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(76),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),       blank,  REDUCE(86),  REDUCE(86),       blank,  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),       blank,  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),  REDUCE(86),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),       blank,  REDUCE(58),  REDUCE(58),       blank,  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),  REDUCE(58),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(137),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(305),   GOTO(138),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(306),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(307),       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),    GOTO(82),    GOTO(83),    GOTO(84),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(142), REDUCE(142),       blank,       blank, REDUCE(142),       blank,       blank, REDUCE(142), REDUCE(142), REDUCE(142), REDUCE(142),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(142), REDUCE(142), REDUCE(142), REDUCE(142), REDUCE(142), REDUCE(142), REDUCE(142), REDUCE(142), REDUCE(142), REDUCE(142), REDUCE(142), REDUCE(142), REDUCE(142), REDUCE(142), REDUCE(142), REDUCE(142), REDUCE(142), REDUCE(142), REDUCE(142), REDUCE(142), REDUCE(142), REDUCE(142), REDUCE(142), REDUCE(142), REDUCE(142), REDUCE(142), REDUCE(142), REDUCE(142), REDUCE(142), REDUCE(142), REDUCE(142), REDUCE(142), REDUCE(142), REDUCE(142),       blank, REDUCE(142), REDUCE(142),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
 REDUCE(148), REDUCE(148), REDUCE(148), REDUCE(148), REDUCE(148), REDUCE(148), REDUCE(148), REDUCE(148), REDUCE(148), REDUCE(148), REDUCE(148),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(148), REDUCE(148), REDUCE(148), REDUCE(148),       blank,       blank,       blank,       blank, REDUCE(148),       blank,       blank,       blank, REDUCE(148), REDUCE(148),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(148), REDUCE(148),       blank,       blank,       blank,       blank, REDUCE(148), REDUCE(148), REDUCE(148),       blank, REDUCE(148), REDUCE(148), REDUCE(148),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(146),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(158),  SHIFT(159),  SHIFT(146),  SHIFT(147),  SHIFT(148),  SHIFT(149),  SHIFT(150),  SHIFT(151),  SHIFT(152),  SHIFT(153),  SHIFT(154),  SHIFT(155),  SHIFT(156),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(157),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
 REDUCE(147), REDUCE(147), REDUCE(147), REDUCE(147), REDUCE(147), REDUCE(147), REDUCE(147), REDUCE(147), REDUCE(147), REDUCE(147), REDUCE(147),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(147), REDUCE(147), REDUCE(147), REDUCE(147),       blank,       blank,       blank,       blank, REDUCE(147),       blank,       blank,       blank, REDUCE(147), REDUCE(147),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(147), REDUCE(147),       blank,       blank,       blank,       blank, REDUCE(147), REDUCE(147), REDUCE(147),       blank, REDUCE(147), REDUCE(147), REDUCE(147),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(158),  SHIFT(159),  SHIFT(146),  SHIFT(147),  SHIFT(148),  SHIFT(149),  SHIFT(150),  SHIFT(151),  SHIFT(152),  SHIFT(153),  SHIFT(154),  SHIFT(155),  SHIFT(156),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(157),  SHIFT(291),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(308),       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),    GOTO(82),    GOTO(83),    GOTO(84),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(169), REDUCE(169),       blank,       blank, REDUCE(169),       blank,       blank, REDUCE(169), REDUCE(169), REDUCE(169), REDUCE(169),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(169), REDUCE(169), REDUCE(169), REDUCE(169), REDUCE(169), REDUCE(169), REDUCE(169), REDUCE(169), REDUCE(169), REDUCE(169), REDUCE(169), REDUCE(169), REDUCE(169), REDUCE(169), REDUCE(169), REDUCE(169), REDUCE(169), REDUCE(169), REDUCE(169), REDUCE(169), REDUCE(169), REDUCE(169), REDUCE(169), REDUCE(169), REDUCE(169), REDUCE(169), REDUCE(169), REDUCE(169), REDUCE(169), REDUCE(169), REDUCE(169), REDUCE(169), REDUCE(169), REDUCE(169),       blank, REDUCE(169), REDUCE(169),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(154), REDUCE(154),       blank,       blank, REDUCE(154),       blank,       blank, REDUCE(154), REDUCE(154), REDUCE(154), REDUCE(154),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(154), REDUCE(154), REDUCE(154), REDUCE(154), REDUCE(154), REDUCE(154), REDUCE(154), REDUCE(154), REDUCE(154), REDUCE(154), REDUCE(154), REDUCE(154), REDUCE(154), REDUCE(154), REDUCE(154), REDUCE(154), REDUCE(154), REDUCE(154), REDUCE(154), REDUCE(154), REDUCE(154), REDUCE(154), REDUCE(154), REDUCE(154), REDUCE(154), REDUCE(154), REDUCE(154), REDUCE(154), REDUCE(154), REDUCE(154), REDUCE(154), REDUCE(154), REDUCE(154), REDUCE(154),       blank, REDUCE(154), REDUCE(154),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(92),  REDUCE(92),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,  SHIFT(137),       blank,  SHIFT(121),       blank,       blank,       blank,  SHIFT(128),       blank,  SHIFT(141),  SHIFT(140),  SHIFT(142),  SHIFT(132),       blank,       blank,  SHIFT(133),  SHIFT(134),  SHIFT(135),  SHIFT(144),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(309),   GOTO(126),   GOTO(138),   GOTO(127),   GOTO(139),       blank,       blank,   GOTO(129),   GOTO(130),       blank,       blank,   GOTO(131),       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(136),   GOTO(143),       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),    GOTO(82),    GOTO(83),    GOTO(84),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
  REDUCE(94),  REDUCE(94),  REDUCE(94),  REDUCE(94),  REDUCE(94),  REDUCE(94),  REDUCE(94),  REDUCE(94),  REDUCE(94),  REDUCE(94),  REDUCE(94),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(94),  REDUCE(94),  REDUCE(94),  REDUCE(94),       blank,       blank,       blank,       blank,  REDUCE(94),       blank,  REDUCE(94),       blank,  REDUCE(94),       blank,       blank,  REDUCE(94),  REDUCE(94),       blank,  REDUCE(94),  REDUCE(94),  REDUCE(94),  REDUCE(94),       blank,       blank,  REDUCE(94),  REDUCE(94),  REDUCE(94),  REDUCE(94),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(94),  REDUCE(94),       blank,       blank,       blank,       blank,  REDUCE(94),  REDUCE(94),  REDUCE(94),       blank,  REDUCE(94),  REDUCE(94),  REDUCE(94),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(310),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,  SHIFT(137),       blank,  SHIFT(121),       blank,       blank,       blank,  SHIFT(128),       blank,  SHIFT(141),  SHIFT(140),  SHIFT(142),  SHIFT(132),       blank,       blank,  SHIFT(133),  SHIFT(134),  SHIFT(135),  SHIFT(144),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(311),   GOTO(126),   GOTO(138),   GOTO(127),   GOTO(139),       blank,       blank,   GOTO(129),   GOTO(130),       blank,       blank,   GOTO(131),       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(136),   GOTO(143),       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),    GOTO(82),    GOTO(83),    GOTO(84),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(312),       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),    GOTO(82),    GOTO(83),    GOTO(84),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(314),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(313),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),       blank,  REDUCE(61),  REDUCE(61),       blank,  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),       blank,  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),  REDUCE(61),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(315),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(160),       blank,       blank,       blank, REDUCE(160), REDUCE(160), REDUCE(160),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(160), REDUCE(160), REDUCE(160), REDUCE(160), REDUCE(160), REDUCE(160), REDUCE(160), REDUCE(160), REDUCE(160), REDUCE(160), REDUCE(160), REDUCE(160), REDUCE(160),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(160), REDUCE(160),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank, REDUCE(171),       blank,       blank,       blank,       blank, REDUCE(171),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),       blank,  REDUCE(66),  REDUCE(66),       blank,  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),       blank,  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),  REDUCE(66),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),       blank,  REDUCE(69),  REDUCE(69),       blank,  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),       blank,  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),  REDUCE(69),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),       blank,  REDUCE(71),  REDUCE(71),       blank,  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),       blank,  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),  REDUCE(71),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(72),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(320),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(318),  SHIFT(319),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(316),   GOTO(317),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(78),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(78),  REDUCE(78),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(321),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(77),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(77),  REDUCE(77),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,  SHIFT(137),       blank,  SHIFT(121),       blank,       blank,       blank,  SHIFT(128),       blank,  SHIFT(141),  SHIFT(140),  SHIFT(142),  SHIFT(132),       blank,       blank,  SHIFT(133),  SHIFT(134),  SHIFT(135),  SHIFT(144),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(322),   GOTO(126),   GOTO(138),   GOTO(127),   GOTO(139),       blank,       blank,   GOTO(129),   GOTO(130),       blank,       blank,   GOTO(131),       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(136),   GOTO(143),       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),    GOTO(82),    GOTO(83),    GOTO(84),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(323),       blank,       blank,   GOTO(324),       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),    GOTO(82),    GOTO(83),    GOTO(84),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(325),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),       blank,  REDUCE(75),  REDUCE(75),       blank,  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),       blank,  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),  REDUCE(75),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(63),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(79),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(79),  REDUCE(79),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(326),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(327),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(83),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(83),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
  REDUCE(81),  REDUCE(81),  REDUCE(81),  REDUCE(81),  REDUCE(81),  REDUCE(81),  REDUCE(81),  REDUCE(81),  REDUCE(81),  REDUCE(81),  REDUCE(81),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(81),  REDUCE(81),  REDUCE(81),  REDUCE(81),       blank,       blank,       blank,       blank,  REDUCE(81),       blank,  REDUCE(81),       blank,  REDUCE(81),       blank,       blank,       blank,  REDUCE(81),       blank,  REDUCE(81),  REDUCE(81),  REDUCE(81),  REDUCE(81),       blank,       blank,  REDUCE(81),  REDUCE(81),  REDUCE(81),  REDUCE(81),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(81),  REDUCE(81),       blank,       blank,       blank,       blank,  REDUCE(81),  REDUCE(81),  REDUCE(81),       blank,  REDUCE(81),  REDUCE(81),  REDUCE(81),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
  SHIFT(107),  SHIFT(108),  SHIFT(109),  SHIFT(110),  SHIFT(111),  SHIFT(112),  SHIFT(113),  SHIFT(114),  SHIFT(115),  SHIFT(122),   SHIFT(98),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  SHIFT(118),  SHIFT(101),   SHIFT(99),  SHIFT(102),       blank,       blank,       blank,       blank,   SHIFT(97),       blank,       blank,       blank,  SHIFT(121),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(93),   SHIFT(94),       blank,       blank,       blank,       blank,   SHIFT(91),   SHIFT(92),   SHIFT(95),       blank,  SHIFT(119),   SHIFT(96),  SHIFT(103),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(104),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   GOTO(328),       blank,       blank,       blank,   GOTO(100),       blank,   GOTO(105),   GOTO(106),       blank,    GOTO(90),   GOTO(117),       blank,       blank,       blank,       blank,       blank,   GOTO(116),   GOTO(120),    GOTO(82),    GOTO(83),    GOTO(84),    GOTO(85),    GOTO(86),    GOTO(87),    GOTO(88),    GOTO(89),
  REDUCE(80),  REDUCE(80),  REDUCE(80),  REDUCE(80),  REDUCE(80),  REDUCE(80),  REDUCE(80),  REDUCE(80),  REDUCE(80),  REDUCE(80),  REDUCE(80),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(80),  REDUCE(80),  REDUCE(80),  REDUCE(80),       blank,       blank,       blank,       blank,  REDUCE(80),       blank,  REDUCE(80),       blank,  REDUCE(80),       blank,       blank,       blank,  REDUCE(80),       blank,  REDUCE(80),  REDUCE(80),  REDUCE(80),  REDUCE(80),       blank,       blank,  REDUCE(80),  REDUCE(80),  REDUCE(80),  REDUCE(80),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(80),  REDUCE(80),       blank,       blank,       blank,       blank,  REDUCE(80),  REDUCE(80),  REDUCE(80),       blank,  REDUCE(80),  REDUCE(80),  REDUCE(80),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(82),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(82),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
};/*}}}*/

/*
 * methods of generated structures
 */

// -- delegate_s --
@begin
methods delegate_s
@end

// -- delegates_s --
@begin
methods delegates_s
@end

// -- name_pos_array_s --
// -- ri_ep_array_s --
// -- idx_size_array_s --
@begin
methods name_pos_array_s
@end

// -- try_fg_map_s --
@begin
methods try_fg_map_s
@end

// -- try_fg_maps_s --
@begin
methods try_fg_maps_s
@end

// -- namespace_record_s --
@begin
methods namespace_record_s
@end

// -- namespace_records_s --
@begin
methods namespace_records_s
@end

// -- class_record_s --
@begin
methods class_record_s
@end

// -- class_records_s --
@begin
methods class_records_s
@end

// -- method_record_s --
@begin
methods method_record_s
@end

// -- method_records_s --
@begin
methods method_records_s
@end

// -- variable_record_s --
@begin
methods variable_record_s
@end

// -- variable_records_s --
@begin
methods variable_records_s
@end

// -- expression_s --
// -- flow_graph_s --
@begin
methods expression_s
@end

// -- expressions_s --
// -- flow_graphs_s --
@begin
methods expressions_s
@end

// -- expression_descr_s --
@begin
methods expression_descr_s
@end

// -- expression_descrs_s --
@begin
methods expression_descrs_s
@end

// -- exp_flow_graph_s --
@begin
methods exp_flow_graph_s
@end

// -- exp_flow_graphs_s --
@begin
methods exp_flow_graphs_s
@end

// -- flow_graph_descr_s --
@begin
methods flow_graph_descr_s
@end

// -- code_descr_s --
@begin
methods code_descr_s
@end

// -- code_descrs_s --
@begin
methods code_descrs_s
@end

// -- im_descr_s --
@begin
methods im_descr_s
@end

// -- script_parser_s --
@begin
methods script_parser_s
@end

unsigned script_parser_s::resolve_namespace_idx_by_name_idx(unsigned a_name_idx)
{/*{{{*/

  // - search for name in used namespaces -
  if (using_namespace_idxs.used != 0)
  {
    unsigned *uni_ptr = using_namespace_idxs.data + using_namespace_idxs.used;
    unsigned *uni_ptr_end = using_namespace_idxs.data;
    do {
      --uni_ptr;

      // - search for name in namespace -
      ui_array_s &ns_namespace_records = namespace_records[*uni_ptr].namespace_record_idxs;
      if (ns_namespace_records.used != 0)
      {
        unsigned *nsni_ptr = ns_namespace_records.data;
        unsigned *nsni_ptr_end = nsni_ptr + ns_namespace_records.used;
        do {
          if (namespace_records[*nsni_ptr].name_idx == a_name_idx)
          {
            return *nsni_ptr;
          }
        } while(++nsni_ptr < nsni_ptr_end);
      }

    } while(uni_ptr > uni_ptr_end);
  }

  return c_idx_not_exist;
}/*}}}*/

unsigned script_parser_s::get_parent_namespace_namespace_idx_by_name_idx(unsigned a_name_idx,unsigned a_namespace_idx)
{/*{{{*/
  if (a_namespace_idx == c_idx_not_exist)
  {
    return c_idx_not_exist;
  }

  // - search in namespaces enclosed in parent namespace  -
  ui_array_s &pnn_records_idxs = namespace_records[a_namespace_idx].namespace_record_idxs;

  if (pnn_records_idxs.used != 0)
  {
    unsigned *nri_ptr = pnn_records_idxs.data;
    unsigned *nri_ptr_end = nri_ptr + pnn_records_idxs.used;
    do {
      if (namespace_records[*nri_ptr].name_idx == a_name_idx)
      {
        return *nri_ptr;
      }
    } while(++nri_ptr < nri_ptr_end);
  }

  return c_idx_not_exist;
}/*}}}*/

unsigned script_parser_s::get_nested_enclosing_class_idx_by_name_idx(unsigned a_name_idx,unsigned a_class_idx)
{/*{{{*/

  // - if parent class does exist -
  if (a_class_idx != c_idx_not_exist)
  {
    // - test parent class name -
    class_record_s &parent_class = class_records[a_class_idx];
    if (parent_class.name_idx == a_name_idx)
    {
      return a_class_idx;
    }

    // - search in parent class members -
    {
      ui_array_s &pc_record_idxs = parent_class.class_record_idxs;

      if (pc_record_idxs.used != 0)
      {
        unsigned *pcri_ptr = pc_record_idxs.data;
        unsigned *pcri_ptr_end = pcri_ptr + pc_record_idxs.used;

        do
        {
          if (class_records[*pcri_ptr].name_idx == a_name_idx)
          {
            return *pcri_ptr;
          }
        }
        while(++pcri_ptr < pcri_ptr_end);
      }
    }

    // - search in parent enclosing classes -
    {
      unsigned class_idx = parent_class.parent_record;

      if(class_idx != c_idx_not_exist)
      {
        do
        {
          class_record_s &class_record = class_records[class_idx];

          if (class_record.name_idx == a_name_idx)
          {
            return class_idx;
          }

          class_idx = class_record.parent_record;
        }
        while(class_idx != c_idx_not_exist);
      }
    }
  }

  // - search for name in used namespaces -
  if (using_namespace_idxs.used != 0)
  {
    unsigned *uni_ptr = using_namespace_idxs.data + using_namespace_idxs.used;
    unsigned *uni_ptr_end = using_namespace_idxs.data;
    do {
      --uni_ptr;

      // - search for name in namespace -
      ui_array_s &ns_class_records = namespace_records[*uni_ptr].class_record_idxs;
      if (ns_class_records.used != 0)
      {
        unsigned *nsci_ptr = ns_class_records.data;
        unsigned *nsci_ptr_end = nsci_ptr + ns_class_records.used;
        do {
          if (class_records[*nsci_ptr].name_idx == a_name_idx)
          {
            return *nsci_ptr;
          }
        } while(++nsci_ptr < nsci_ptr_end);
      }

    } while(uni_ptr > uni_ptr_end);
  }

  return c_idx_not_exist;
}/*}}}*/

unsigned script_parser_s::resolve_class_idx_by_name_idx(unsigned a_name_idx,unsigned a_class_idx)
{/*{{{*/

  // - if exist base (main) class -
  if (a_class_idx != c_idx_not_exist)
  {
    // - cycle through nested classes -
    do
    {
      class_record_s &class_record = class_records[a_class_idx];

      // - reference to array of nested class indexes -
      ui_array_s &class_record_idxs = class_record.class_record_idxs;

      if (class_record_idxs.used != 0)
      {
        unsigned *cri_ptr = class_record_idxs.data;
        unsigned *cri_ptr_end = cri_ptr + class_record_idxs.used;

        // - cycle through all classes nested in this class -
        do
        {
          if (class_records[*cri_ptr].name_idx == a_name_idx)
          {
            return *cri_ptr;
          }
        }
        while(++cri_ptr < cri_ptr_end);
      }

      // - if next parent class doesnt exist -
      if (class_record.parent_record == c_idx_not_exist)
      {
        if (class_record.name_idx == a_name_idx)
        {
          return a_class_idx;
        }

        break;
      }

      a_class_idx = class_record.parent_record;

    }
    while(true);
  }

  // - search for name in used namespaces -
  if (using_namespace_idxs.used != 0)
  {
    unsigned *uni_ptr = using_namespace_idxs.data + using_namespace_idxs.used;
    unsigned *uni_ptr_end = using_namespace_idxs.data;
    do {
      --uni_ptr;

      // - search for name in namespace -
      ui_array_s &ns_class_records = namespace_records[*uni_ptr].class_record_idxs;
      if (ns_class_records.used != 0)
      {
        unsigned *nsci_ptr = ns_class_records.data;
        unsigned *nsci_ptr_end = nsci_ptr + ns_class_records.used;
        do {
          if (class_records[*nsci_ptr].name_idx == a_name_idx)
          {
            return *nsci_ptr;
          }
        } while(++nsci_ptr < nsci_ptr_end);
      }

    } while(uni_ptr > uni_ptr_end);
  }

  return c_idx_not_exist;
}/*}}}*/

unsigned script_parser_s::get_parent_namespace_class_idx_by_name_idx(unsigned a_name_idx,unsigned a_namespace_idx)
{/*{{{*/

  // - test if name belong to parent namespace -
  ui_array_s &top_ns_class_records = namespace_records[a_namespace_idx].class_record_idxs;
  if (top_ns_class_records.used != 0)
  {
    unsigned *tni_ptr = top_ns_class_records.data;
    unsigned *tni_ptr_end = tni_ptr + top_ns_class_records.used;
    do
    {
      if (class_records[*tni_ptr].name_idx == a_name_idx)
      {
        return *tni_ptr;
      }
    }
    while(++tni_ptr < tni_ptr_end);
  }

  return c_idx_not_exist;
}/*}}}*/

#if (DEBUG_MESSAGES >= 1) && (SYSTEM_TYPE != SYSTEM_TYPE_DSP)
void script_parser_s::DEBUG_show_variables()
{/*{{{*/
  if (variable_records.used != 0)
  {
    variable_record_s *vr_ptr = variable_records.data;
    variable_record_s *vr_ptr_end = vr_ptr + variable_records.used;

    do
    {
      printf(" ## VARIABLE: %s ## \n",variable_symbol_names[vr_ptr->name_idx].data);

      printf("modifiers: ");
      if (vr_ptr->modifiers & c_modifier_public) printf("public ");
      if (vr_ptr->modifiers & c_modifier_private) printf("private ");
      if (vr_ptr->modifiers & c_modifier_static) printf("static ");
      if (vr_ptr->modifiers & c_modifier_abstract) printf("abstract ");
      if (vr_ptr->modifiers & c_modifier_final) printf("final ");

      if (vr_ptr->modifiers & c_variable_modifier_blank) printf("blank ");
      if (vr_ptr->modifiers & c_variable_modifier_reference) printf("reference ");
      putchar('\n');

      printf("parent_record: %u\n",vr_ptr->parent_record);
      printf("init_expression_idx: %u\n",vr_ptr->init_expression_idx);

      name_pos_s &name_position = vr_ptr->name_position;
      printf("name_position: %u - %u\n",name_position.ui_first,name_position.ui_second);
    }
    while(++vr_ptr < vr_ptr_end);
  }
}/*}}}*/

void script_parser_s::DEBUG_show_methods()
{/*{{{*/
  if (method_records.used != 0)
  {
    method_record_s *mr_ptr = method_records.data;
    method_record_s *mr_ptr_end = mr_ptr + method_records.used;

    do
    {
      if (mr_ptr->name_idx != c_idx_not_exist)
      {
        printf(" ## METHOD: %s ## \n",method_symbol_names[mr_ptr->name_idx].data);
      }
      else
      {
        printf(" ## METHOD: <anon_%u> ## \n",(unsigned)(mr_ptr - method_records.data));
      }

      printf("modifiers: ");
      if (mr_ptr->modifiers & c_modifier_public) printf("public ");
      if (mr_ptr->modifiers & c_modifier_private) printf("private ");
      if (mr_ptr->modifiers & c_modifier_static) printf("static ");
      if (mr_ptr->modifiers & c_modifier_abstract) printf("abstract ");
      if (mr_ptr->modifiers & c_modifier_final) printf("final ");

      if (mr_ptr->modifiers & c_variable_modifier_blank) printf("blank ");
      if (mr_ptr->modifiers & c_variable_modifier_reference) printf("reference ");
      putchar('\n');

      if (mr_ptr->parent_record != c_idx_not_exist)
      {
        printf("parent_record(class): %s\n",class_symbol_names[class_records[mr_ptr->parent_record].name_idx].data);
      }
      else
      {
        printf("parent_record(class): <none>\n");
      }

      printf("flow_graph_idx: %u\n",mr_ptr->flow_graph_idx);

      printf("try_fg_maps:");
      if (mr_ptr->try_fg_maps.used != 0 )
      {
        putchar('\n');

        try_fg_map_s *fgm_ptr = mr_ptr->try_fg_maps.data;
        try_fg_map_s *fgm_ptr_end = fgm_ptr + mr_ptr->try_fg_maps.used;
        do
        {
          printf("   from: %u to: %u -> ",fgm_ptr->tfgm_first_fg_node,fgm_ptr->tfgm_last_fg_node);

          if (fgm_ptr->tfgm_fg_idx != c_idx_not_exist)
          {
            printf("%d\n",fgm_ptr->tfgm_fg_idx);
          }
          else
          {
            printf("none\n");
          }
        }
        while(++fgm_ptr < fgm_ptr_end);
      }
      else
      {
        printf(" none\n");
      }

      name_pos_s &name_position = mr_ptr->name_position;
      printf("name_position: %u - %u\n",name_position.ui_first,name_position.ui_second);

    }
    while(++mr_ptr < mr_ptr_end);
  }
}/*}}}*/

void script_parser_s::DEBUG_show_classes()
{/*{{{*/
  if (class_records.used != 0)
  {
    class_record_s *cr_ptr = class_records.data;
    class_record_s *cr_ptr_end = cr_ptr + class_records.used;

    do
    {
      printf(" ## CLASS: %s ## \n",class_symbol_names[cr_ptr->name_idx].data);

      printf("modifiers: ");
      if (cr_ptr->modifiers & c_modifier_public) printf("public ");
      if (cr_ptr->modifiers & c_modifier_private) printf("private ");
      if (cr_ptr->modifiers & c_modifier_static) printf("static ");
      if (cr_ptr->modifiers & c_modifier_abstract) printf("abstract ");
      if (cr_ptr->modifiers & c_modifier_final) printf("final ");

      if (cr_ptr->modifiers & c_variable_modifier_blank) printf("blank ");
      if (cr_ptr->modifiers & c_variable_modifier_reference) printf("reference ");
      putchar('\n');

      printf("parent_record: %u\n",cr_ptr->parent_record);
      printf("extend_class_idx: %u\n",cr_ptr->extend_class_idx);

      name_pos_s &name_position = cr_ptr->name_position;
      printf("name_position: %u - %u\n",name_position.ui_first,name_position.ui_second);

      printf("element_cnt: %u\n",cr_ptr->element_cnt);
      printf("stack_size: %u\n",cr_ptr->stack_size);

    }
    while(++cr_ptr < cr_ptr_end);
  }
}/*}}}*/

void script_parser_s::DEBUG_show_namespaces()
{/*{{{*/
  ui_array_s namespace_stack;
  namespace_stack.init();

  // - insert global namespace index, first index -
  namespace_stack.push(0);
  namespace_stack.push(0);

  do {
    unsigned index = namespace_stack.pop();
    namespace_record_s &namespace_record = namespace_records[namespace_stack.last()];

    if (index == 0)
    {
      printf("NAMESPACE: ");

      // - print namespace information -
      unsigned *nsri_ptr = namespace_stack.data;
      unsigned *nsri_ptr_end = nsri_ptr + namespace_stack.used - 1;

      if (nsri_ptr < nsri_ptr_end)
      {
        do {
          printf("%s.",class_symbol_names[namespace_records[*nsri_ptr].name_idx].data);
        } while((nsri_ptr += 2) < nsri_ptr_end);
      }

      printf("%s:",class_symbol_names[namespace_record.name_idx].data);

      // - print namespace classes -
      ui_array_s &class_record_idxs = namespace_record.class_record_idxs;

      if (class_record_idxs.used != 0)
      {
        unsigned *cri_ptr = class_record_idxs.data;
        unsigned *cri_ptr_end = cri_ptr + class_record_idxs.used;
        do {
          printf(" %s",class_symbol_names[class_records[*cri_ptr].name_idx].data);
        } while(++cri_ptr < cri_ptr_end);
      }

      putchar('\n');
    }

    // - if namespace at index is available -
    if (index < namespace_record.namespace_record_idxs.used)
    {
      namespace_stack.push(index + 1);
      namespace_stack.push(namespace_record.namespace_record_idxs[index]);
      namespace_stack.push(0);
    }
    else
    {
      // - remove namespace index -
      namespace_stack.pop();
    }

  } while(namespace_stack.used > 0);

  namespace_stack.clear();
}/*}}}*/

void script_parser_s::DEBUG_print_spaces(unsigned space_cnt)
{/*{{{*/
  if (space_cnt != 0)
  {
    do
    {
      printf("    ");
    }
    while(--space_cnt > 0);
  }
}/*}}}*/

void script_parser_s::DEBUG_show_expression(expression_s &exp)
{/*{{{*/
  printf("## EXPRESSION TREE ##\n");

  ui_array_s exp_stack;
  exp_stack.init();
  exp_stack.push(exp.start_node_idx);

  ui_array_s deep_stack;
  deep_stack.init();
  deep_stack.push(1);

  do
  {
    unsigned exp_idx = exp_stack.pop();
    unsigned *exp_ptr = exp.nodes.data + exp_idx;
    unsigned deep = deep_stack.pop();

    switch (*exp_ptr)
    {
    case c_node_type_elements_array:
    {
      DEBUG_print_spaces(deep);
      printf("#%u elements array\n",exp_idx);

      unsigned member_cnt = exp_ptr[2];

      if (member_cnt != 0)
      {
        unsigned m_idx = member_cnt;
        do
        {
          m_idx--;

          exp_stack.push(exp_ptr[m_idx + 3]);
          deep_stack.push(deep + 1);
        }
        while(m_idx > 0);
      }
    }
    break;
    case c_node_type_switch_test:
    {
      DEBUG_print_spaces(deep);
      printf("#%u switch test\n",exp_idx);

      unsigned value_cnt = exp_ptr[2];

      if (value_cnt != 0)
      {
        unsigned v_idx = value_cnt;
        do
        {
          v_idx--;

          exp_stack.push(exp_ptr[v_idx + 3]);
          deep_stack.push(deep + 1);
        }
        while(v_idx > 0);
      }
    }
    break;
    case c_node_type_slice_range:
    {
      DEBUG_print_spaces(deep);
      printf("#%u slice range\n",exp_idx);

      unsigned v_idx = 4;
      do
      {
        v_idx--;

        exp_stack.push(exp_ptr[v_idx + 2]);
        deep_stack.push(deep + 1);
      }
      while(v_idx > 0);
    }
    break;
    case c_node_type_operator_binary_equal:
      DEBUG_print_spaces(deep);
      printf("#%u operator_binary_equal\n",exp_idx);

      exp_stack.push(exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      deep_stack.push(deep + 1);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_operator_binary_plus_equal:
      DEBUG_print_spaces(deep);
      printf("#%u operator_binary_plus_equal\n",exp_idx);

      exp_stack.push(exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      deep_stack.push(deep + 1);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_operator_binary_minus_equal:
      DEBUG_print_spaces(deep);
      printf("#%u operator_binary_minus_equal\n",exp_idx);

      exp_stack.push(exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      deep_stack.push(deep + 1);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_operator_binary_asterisk_equal:
      DEBUG_print_spaces(deep);
      printf("#%u operator_binary_asterisk_equal\n",exp_idx);

      exp_stack.push(exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      deep_stack.push(deep + 1);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_operator_binary_slash_equal:
      DEBUG_print_spaces(deep);
      printf("#%u operator_binary_slash_equal\n",exp_idx);

      exp_stack.push(exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      deep_stack.push(deep + 1);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_operator_binary_percent_equal:
      DEBUG_print_spaces(deep);
      printf("#%u operator_binary_percent_equal\n",exp_idx);

      exp_stack.push(exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      deep_stack.push(deep + 1);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_operator_binary_double_ls_br_equal:
      DEBUG_print_spaces(deep);
      printf("#%u operator_binary_double_ls_br_equal\n",exp_idx);

      exp_stack.push(exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      deep_stack.push(deep + 1);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_operator_binary_double_rs_br_equal:
      DEBUG_print_spaces(deep);
      printf("#%u operator_binary_double_rs_br_equal\n",exp_idx);

      exp_stack.push(exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      deep_stack.push(deep + 1);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_operator_binary_ampersand_equal:
      DEBUG_print_spaces(deep);
      printf("#%u operator_binary_ampersand_equal\n",exp_idx);

      exp_stack.push(exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      deep_stack.push(deep + 1);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_operator_binary_pipe_equal:
      DEBUG_print_spaces(deep);
      printf("#%u operator_binary_pipe_equal\n",exp_idx);

      exp_stack.push(exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      deep_stack.push(deep + 1);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_operator_binary_circumflex_equal:
      DEBUG_print_spaces(deep);
      printf("#%u operator_binary_circumflex_equal\n",exp_idx);

      exp_stack.push(exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      deep_stack.push(deep + 1);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_operator_binary_double_ampersand:
      DEBUG_print_spaces(deep);
      printf("#%u operator_binary_double_ampersand\n",exp_idx);

      exp_stack.push(exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      deep_stack.push(deep + 1);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_operator_binary_double_pipe:
      DEBUG_print_spaces(deep);
      printf("#%u operator_binary_double_pipe\n",exp_idx);

      exp_stack.push(exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      deep_stack.push(deep + 1);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_operator_binary_ampersand:
      DEBUG_print_spaces(deep);
      printf("#%u operator_binary_ampersand\n",exp_idx);

      exp_stack.push(exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      deep_stack.push(deep + 1);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_operator_binary_pipe:
      DEBUG_print_spaces(deep);
      printf("#%u operator_binary_pipe\n",exp_idx);

      exp_stack.push(exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      deep_stack.push(deep + 1);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_operator_binary_circumflex:
      DEBUG_print_spaces(deep);
      printf("#%u operator_binary_circumflex\n",exp_idx);

      exp_stack.push(exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      deep_stack.push(deep + 1);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_operator_binary_double_equal:
      DEBUG_print_spaces(deep);
      printf("#%u operator_binary_double_equal\n",exp_idx);

      exp_stack.push(exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      deep_stack.push(deep + 1);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_operator_binary_exclamation_equal:
      DEBUG_print_spaces(deep);
      printf("#%u operator_binary_exclamation_equal\n",exp_idx);

      exp_stack.push(exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      deep_stack.push(deep + 1);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_operator_binary_rs_br:
      DEBUG_print_spaces(deep);
      printf("#%u operator_binary_rs_br\n",exp_idx);

      exp_stack.push(exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      deep_stack.push(deep + 1);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_operator_binary_ls_br:
      DEBUG_print_spaces(deep);
      printf("#%u operator_binary_ls_br\n",exp_idx);

      exp_stack.push(exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      deep_stack.push(deep + 1);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_operator_binary_rs_br_equal:
      DEBUG_print_spaces(deep);
      printf("#%u operator_binary_rs_br_equal\n",exp_idx);

      exp_stack.push(exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      deep_stack.push(deep + 1);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_operator_binary_ls_br_equal:
      DEBUG_print_spaces(deep);
      printf("#%u operator_binary_ls_br_equal\n",exp_idx);

      exp_stack.push(exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      deep_stack.push(deep + 1);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_operator_binary_double_rs_br:
      DEBUG_print_spaces(deep);
      printf("#%u operator_binary_double_rs_br\n",exp_idx);

      exp_stack.push(exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      deep_stack.push(deep + 1);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_operator_binary_double_ls_br:
      DEBUG_print_spaces(deep);
      printf("#%u operator_binary_double_ls_br\n",exp_idx);

      exp_stack.push(exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      deep_stack.push(deep + 1);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_operator_binary_plus:
      DEBUG_print_spaces(deep);
      printf("#%u operator_binary_plus\n",exp_idx);

      exp_stack.push(exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      deep_stack.push(deep + 1);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_operator_binary_minus:
      DEBUG_print_spaces(deep);
      printf("#%u operator_binary_minus\n",exp_idx);

      exp_stack.push(exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      deep_stack.push(deep + 1);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_operator_binary_asterisk:
      DEBUG_print_spaces(deep);
      printf("#%u operator_binary_asterisk\n",exp_idx);

      exp_stack.push(exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      deep_stack.push(deep + 1);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_operator_binary_slash:
      DEBUG_print_spaces(deep);
      printf("#%u operator_binary_slash\n",exp_idx);

      exp_stack.push(exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      deep_stack.push(deep + 1);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_operator_binary_percent:
      DEBUG_print_spaces(deep);
      printf("#%u operator_binary_percent\n",exp_idx);

      exp_stack.push(exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      deep_stack.push(deep + 1);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_operator_unary_post_double_plus:
      DEBUG_print_spaces(deep);
      printf("#%u operator_unary_post_double_plus\n",exp_idx);

      exp_stack.push(exp_ptr[2]);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_operator_unary_post_double_minus:
      DEBUG_print_spaces(deep);
      printf("#%u operator_unary_post_double_minus\n",exp_idx);

      exp_stack.push(exp_ptr[2]);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_operator_unary_pre_double_plus:
      DEBUG_print_spaces(deep);
      printf("#%u operator_unary_pre_double_plus\n",exp_idx);

      exp_stack.push(exp_ptr[2]);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_operator_unary_pre_double_minus:
      DEBUG_print_spaces(deep);
      printf("#%u operator_unary_pre_double_minus\n",exp_idx);

      exp_stack.push(exp_ptr[2]);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_operator_unary_pre_plus:
      DEBUG_print_spaces(deep);
      printf("#%u operator_unary_pre_plus\n",exp_idx);

      exp_stack.push(exp_ptr[2]);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_operator_unary_pre_minus:
      DEBUG_print_spaces(deep);
      printf("#%u operator_unary_pre_minus\n",exp_idx);

      exp_stack.push(exp_ptr[2]);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_operator_unary_pre_exclamation:
      DEBUG_print_spaces(deep);
      printf("#%u operator_unary_pre_exclamation\n",exp_idx);

      exp_stack.push(exp_ptr[2]);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_operator_unary_pre_tilde:
      DEBUG_print_spaces(deep);
      printf("#%u operator_unary_pre_tilde\n",exp_idx);

      exp_stack.push(exp_ptr[2]);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_operator_binary_le_br_re_br:
      DEBUG_print_spaces(deep);
      printf("#%u operator_binary_le_br_re_br\n",exp_idx);

      exp_stack.push(exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      deep_stack.push(deep + 1);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_identifier:
      DEBUG_print_spaces(deep);
      printf("#%u identifier: \"%s\"\n",exp_idx,variable_symbol_names[exp_ptr[2]].data);
      break;
    case c_node_type_element_identifier:
      DEBUG_print_spaces(deep);
      printf("#%u element_identifier: \"%s\"\n",exp_idx,variable_symbol_names[exp_ptr[2]].data);
      break;
    case c_node_type_this_access:
      DEBUG_print_spaces(deep);
      printf("#%u this_access\n",exp_idx);
      break;
    case c_node_type_new_object:
    {
      DEBUG_print_spaces(deep);
      printf("#%u new_object\n",exp_idx);

      unsigned parm_cnt = exp_ptr[2];

      if (parm_cnt != 0)
      {
        unsigned parm_idx = parm_cnt;
        do
        {
          parm_idx--;

          exp_stack.push(exp_ptr[parm_idx + 4]);
          deep_stack.push(deep + 1);
        }
        while(parm_idx > 0);
      }

      exp_stack.push(exp_ptr[3]);
      deep_stack.push(deep + 1);
    }
    break;
    case c_node_type_new_objects_array:
      DEBUG_print_spaces(deep);
      printf("#%u new_objects_array\n",exp_idx);

      exp_stack.push(exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      deep_stack.push(deep + 1);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_free_object:
      DEBUG_print_spaces(deep);
      printf("#%u free_object\n",exp_idx);

      exp_stack.push(exp_ptr[2]);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_type_identification:
      DEBUG_print_spaces(deep);
      printf("#%u type_identification\n",exp_idx);

      exp_stack.push(exp_ptr[1]);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_object_reference_copy:
      DEBUG_print_spaces(deep);
      printf("#%u object_reference_copy\n",exp_idx);

      exp_stack.push(exp_ptr[2]);
      exp_stack.push(exp_ptr[1]);
      deep_stack.push(deep + 1);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_conditional_expression:
      DEBUG_print_spaces(deep);
      printf("#%u conditional_expression\n",exp_idx);

      exp_stack.push(exp_ptr[4]);
      exp_stack.push(exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      deep_stack.push(deep + 1);
      deep_stack.push(deep + 1);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_logical_and:
      DEBUG_print_spaces(deep);
      printf("#%u logical_and\n",exp_idx);

      exp_stack.push(exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      deep_stack.push(deep + 1);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_logical_or:
      DEBUG_print_spaces(deep);
      printf("#%u logical_or\n",exp_idx);

      exp_stack.push(exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      deep_stack.push(deep + 1);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_class_access:
    {
      DEBUG_print_spaces(deep);
      printf("#%u class_access: ",exp_idx);

      unsigned name_cnt = exp_ptr[2];

      if (name_cnt != 0)
      {
        unsigned *ni_ptr = exp_ptr + 3;
        unsigned *ni_ptr_end = ni_ptr + name_cnt;
        do {
          printf("\"%s\"",class_symbol_names[*ni_ptr].data);

          if (++ni_ptr >= ni_ptr_end)
            break;

          printf(", ");
        } while(true);
      }

      printf("\n");
    }
    break;
    case c_node_type_object_member_select:
      DEBUG_print_spaces(deep);
      printf("#%u object_member_select: \"%s\"\n",exp_idx,variable_symbol_names[exp_ptr[2]].data);

      exp_stack.push(exp_ptr[3]);
      deep_stack.push(deep + 1);
      break;
    case c_node_type_this_method_call:
    {
      DEBUG_print_spaces(deep);
      printf("#%u this_method_call: \"%s\"\n",exp_idx,method_symbol_names[exp_ptr[2]].data);

      unsigned parm_cnt = exp_ptr[3];

      if (parm_cnt != 0)
      {
        unsigned parm_idx = parm_cnt;
        do
        {
          parm_idx--;

          exp_stack.push(exp_ptr[parm_idx + 4]);
          deep_stack.push(deep + 1);
        }
        while(parm_idx > 0);
      }
    }
    break;
    case c_node_type_object_method_call:
    {
      DEBUG_print_spaces(deep);
      printf("#%u object_method_call: \"%s\"\n",exp_idx,method_symbol_names[exp_ptr[2]].data);

      unsigned parm_cnt = exp_ptr[3] + 1;
      unsigned parm_idx = parm_cnt;

      do
      {
        parm_idx--;

        exp_stack.push(exp_ptr[parm_idx + 4]);
        deep_stack.push(deep + 1);
      }
      while(parm_idx > 0);
    }
    break;
    case c_node_type_const_char:
      DEBUG_print_spaces(deep);
      printf("#%u const: \"%c\"\n",exp_idx,const_chars[exp_ptr[1]]);
      break;
    case c_node_type_const_int:
      DEBUG_print_spaces(deep);
      printf("#%u const: \"%" HOST_LL_FORMAT "d\"\n",exp_idx,const_ints[exp_ptr[1]]);
      break;
    case c_node_type_const_float:
      DEBUG_print_spaces(deep);
      printf("#%u const: \"%f\"\n",exp_idx,const_floats[exp_ptr[1]]);
      break;
    case c_node_type_const_string:
      DEBUG_print_spaces(deep);
      printf("#%u const: \"%s\"\n",exp_idx,const_strings[exp_ptr[1]].data);
      break;
    case c_node_type_const_delegate:
      DEBUG_print_spaces(deep);
      printf("#%u const: lambda function\n",exp_idx);
      break;
    default:
      cassert(0);
    }
  }
  while(exp_stack.used > 0);

  deep_stack.clear();
  exp_stack.clear();
}/*}}}*/

void script_parser_s::DEBUG_show_flow_graph(exp_flow_graph_s &fg)
{/*{{{*/
  printf("## FLOW_GRAPH ##\n");

  ui_array_s &fg_nodes = fg.nodes;

  if (fg_nodes.used == 0) return;

  unsigned *fg_data = fg_nodes.data;
  unsigned fg_idx = 0;

  do
  {
    unsigned *fg_ptr = fg_data + fg_idx;

    switch(*fg_ptr)
    {
    case c_fg_type_expression:
      printf("#%u fg_expression: -> %u\n",fg_idx,fg_ptr[c_fg_expression_first_out]);
      DEBUG_show_expression(fg.expressions[fg_ptr[c_fg_expression_idx]]);
      fg_idx += c_fg_expression_size;
      break;
    case c_fg_type_condition:
      printf("#%u fg_condition: + %u, - %u\n",fg_idx,fg_ptr[c_fg_condition_first_out],fg_ptr[c_fg_condition_second_out]);
      DEBUG_show_expression(fg.expressions[fg_ptr[c_fg_expression_idx]]);
      fg_idx += c_fg_condition_size;
      break;
    case c_fg_type_return_expression:
      printf("#%u fg_return_expression\n",fg_idx);
      DEBUG_show_expression(fg.expressions[fg_ptr[c_fg_expression_idx]]);
      fg_idx += c_fg_return_expression_size;
      break;
    case c_fg_type_for_loop:
      printf("#%u fg_for_loop\n",fg_idx);
      DEBUG_show_expression(fg.expressions[fg_ptr[c_fg_expression_idx]]);
      fg_idx += c_fg_for_loop_size;
      break;
    case c_fg_type_break:
      printf("#%u fg_break\n",fg_idx);
      fg_idx += c_fg_break_size;
      break;
    case c_fg_type_continue:
      printf("#%u fg_continue\n",fg_idx);
      fg_idx += c_fg_continue_size;
      break;
    case c_fg_type_switch:
      printf("#%u fg_switch\n",fg_idx);
      DEBUG_show_expression(fg.expressions[fg_ptr[c_fg_expression_idx]]);
      fg_idx += c_fg_switch_size + fg_ptr[c_fg_switch_default_cnt] + fg_ptr[c_fg_switch_exp_cnt];
      break;
    default:
      cassert(0);
    }
  }
  while(fg_idx < fg_nodes.used);
}/*}}}*/

void script_parser_s::DEBUG_show_method_flow_graphs()
{/*{{{*/
  if (method_flow_graphs.used == 0) return;

  unsigned mfg_idx = 0;
  do
  {
    DEBUG_show_flow_graph(method_flow_graphs[mfg_idx]);
  }
  while(++mfg_idx < method_flow_graphs.used);
}/*}}}*/

void script_parser_s::DEBUG_show_init_expressions()
{/*{{{*/
  if (init_expressions.used == 0) return;

  unsigned ie_idx = 0;
  do
  {
    DEBUG_show_expression(init_expressions[ie_idx]);
  }
  while(++ie_idx < init_expressions.used);
}/*}}}*/

void script_parser_s::DEBUG_show_dot_format_expression(expression_s &exp)
{/*{{{*/
  printf(
    "// ## DOT EXPRESSION TREE ##\n"
    "digraph G {\n"
    "   rankdir=TD;\n"
    "   node [shape=ellipse];\n"
  );

  ui_array_s exp_stack;
  exp_stack.init();
  exp_stack.push(exp.start_node_idx);

  do
  {
    unsigned exp_idx = exp_stack.pop();
    unsigned *exp_ptr = exp.nodes.data + exp_idx;

    switch (*exp_ptr)
    {
    case c_node_type_elements_array:
    {
      printf("   nd_%u [ label = \"elements array\" ]\n",exp_idx);

      unsigned member_cnt = exp_ptr[2];

      if (member_cnt != 0)
      {
        unsigned m_idx = 0;
        do
        {
          printf("   nd_%u -> nd_%u\n",exp_idx,exp_ptr[m_idx + 3]);
          exp_stack.push(exp_ptr[m_idx + 3]);
        }
        while(++m_idx < member_cnt);
      }
    }
    break;
    case c_node_type_switch_test:
    {
      printf("   nd_%u [ label = \"switch test\" ]\n",exp_idx);

      unsigned value_cnt = exp_ptr[2];

      if (value_cnt != 0)
      {
        unsigned v_idx = 0;
        do
        {
          printf("   nd_%u -> nd_%u\n",exp_idx,exp_ptr[v_idx + 3]);
          exp_stack.push(exp_ptr[v_idx + 3]);
        }
        while(++v_idx < value_cnt);
      }
    }
    break;
    case c_node_type_slice_range:
    {
      printf("   nd_%u [ label = \"slice range\" ]\n",exp_idx);

      unsigned value_cnt = 4;
      unsigned v_idx = 0;
      do
      {
        printf("   nd_%u -> nd_%u\n",exp_idx,exp_ptr[v_idx + 2]);
        exp_stack.push(exp_ptr[v_idx + 2]);
      }
      while(++v_idx < value_cnt);
    }
    break;
    case c_node_type_operator_binary_equal:
      _printf_p(
        "   nd_%1$u [ label = \"operator_binary_equal\" ]\n"
        "   nd_%1$u -> nd_%2$u\n"
        "   nd_%1$u -> nd_%3$u\n"
        ,exp_idx,exp_ptr[2],exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      exp_stack.push(exp_ptr[3]);
      break;
    case c_node_type_operator_binary_plus_equal:
      _printf_p(
        "   nd_%1$u [ label = \"operator_binary_plus_equal\" ]\n"
        "   nd_%1$u -> nd_%2$u\n"
        "   nd_%1$u -> nd_%3$u\n"
        ,exp_idx,exp_ptr[2],exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      exp_stack.push(exp_ptr[3]);
      break;
    case c_node_type_operator_binary_minus_equal:
      _printf_p(
        "   nd_%1$u [ label = \"operator_binary_minus_equal\" ]\n"
        "   nd_%1$u -> nd_%2$u\n"
        "   nd_%1$u -> nd_%3$u\n"
        ,exp_idx,exp_ptr[2],exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      exp_stack.push(exp_ptr[3]);
      break;
    case c_node_type_operator_binary_asterisk_equal:
      _printf_p(
        "   nd_%1$u [ label = \"operator_binary_asterisk_equal\" ]\n"
        "   nd_%1$u -> nd_%2$u\n"
        "   nd_%1$u -> nd_%3$u\n"
        ,exp_idx,exp_ptr[2],exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      exp_stack.push(exp_ptr[3]);
      break;
    case c_node_type_operator_binary_slash_equal:
      _printf_p(
        "   nd_%1$u [ label = \"operator_binary_slash_equal\" ]\n"
        "   nd_%1$u -> nd_%2$u\n"
        "   nd_%1$u -> nd_%3$u\n"
        ,exp_idx,exp_ptr[2],exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      exp_stack.push(exp_ptr[3]);
      break;
    case c_node_type_operator_binary_percent_equal:
      _printf_p(
        "   nd_%1$u [ label = \"operator_binary_percent_equal\" ]\n"
        "   nd_%1$u -> nd_%2$u\n"
        "   nd_%1$u -> nd_%3$u\n"
        ,exp_idx,exp_ptr[2],exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      exp_stack.push(exp_ptr[3]);
      break;
    case c_node_type_operator_binary_double_ls_br_equal:
      _printf_p(
        "   nd_%1$u [ label = \"operator_binary_double_ls_br_equal\" ]\n"
        "   nd_%1$u -> nd_%2$u\n"
        "   nd_%1$u -> nd_%3$u\n"
        ,exp_idx,exp_ptr[2],exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      exp_stack.push(exp_ptr[3]);
      break;
    case c_node_type_operator_binary_double_rs_br_equal:
      _printf_p(
        "   nd_%1$u [ label = \"operator_binary_double_rs_br_equal\" ]\n"
        "   nd_%1$u -> nd_%2$u\n"
        "   nd_%1$u -> nd_%3$u\n"
        ,exp_idx,exp_ptr[2],exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      exp_stack.push(exp_ptr[3]);
      break;
    case c_node_type_operator_binary_ampersand_equal:
      _printf_p(
        "   nd_%1$u [ label = \"operator_binary_ampersand_equal\" ]\n"
        "   nd_%1$u -> nd_%2$u\n"
        "   nd_%1$u -> nd_%3$u\n"
        ,exp_idx,exp_ptr[2],exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      exp_stack.push(exp_ptr[3]);
      break;
    case c_node_type_operator_binary_pipe_equal:
      _printf_p(
        "   nd_%1$u [ label = \"operator_binary_pipe_equal\" ]\n"
        "   nd_%1$u -> nd_%2$u\n"
        "   nd_%1$u -> nd_%3$u\n"
        ,exp_idx,exp_ptr[2],exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      exp_stack.push(exp_ptr[3]);
      break;
    case c_node_type_operator_binary_circumflex_equal:
      _printf_p(
        "   nd_%1$u [ label = \"operator_binary_circumflex_equal\" ]\n"
        "   nd_%1$u -> nd_%2$u\n"
        "   nd_%1$u -> nd_%3$u\n"
        ,exp_idx,exp_ptr[2],exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      exp_stack.push(exp_ptr[3]);
      break;
    case c_node_type_operator_binary_double_ampersand:
      _printf_p(
        "   nd_%1$u [ label = \"operator_binary_double_ampersand\" ]\n"
        "   nd_%1$u -> nd_%2$u\n"
        "   nd_%1$u -> nd_%3$u\n"
        ,exp_idx,exp_ptr[2],exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      exp_stack.push(exp_ptr[3]);
      break;
    case c_node_type_operator_binary_double_pipe:
      _printf_p(
        "   nd_%1$u [ label = \"operator_binary_double_pipe\" ]\n"
        "   nd_%1$u -> nd_%2$u\n"
        "   nd_%1$u -> nd_%3$u\n"
        ,exp_idx,exp_ptr[2],exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      exp_stack.push(exp_ptr[3]);
      break;
    case c_node_type_operator_binary_ampersand:
      _printf_p(
        "   nd_%1$u [ label = \"operator_binary_ampersand\" ]\n"
        "   nd_%1$u -> nd_%2$u\n"
        "   nd_%1$u -> nd_%3$u\n"
        ,exp_idx,exp_ptr[2],exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      exp_stack.push(exp_ptr[3]);
      break;
    case c_node_type_operator_binary_pipe:
      _printf_p(
        "   nd_%1$u [ label = \"operator_binary_pipe\" ]\n"
        "   nd_%1$u -> nd_%2$u\n"
        "   nd_%1$u -> nd_%3$u\n"
        ,exp_idx,exp_ptr[2],exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      exp_stack.push(exp_ptr[3]);
      break;
    case c_node_type_operator_binary_circumflex:
      _printf_p(
        "   nd_%1$u [ label = \"operator_binary_circumflex\" ]\n"
        "   nd_%1$u -> nd_%2$u\n"
        "   nd_%1$u -> nd_%3$u\n"
        ,exp_idx,exp_ptr[2],exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      exp_stack.push(exp_ptr[3]);
      break;
    case c_node_type_operator_binary_double_equal:
      _printf_p(
        "   nd_%1$u [ label = \"operator_binary_double_equal\" ]\n"
        "   nd_%1$u -> nd_%2$u\n"
        "   nd_%1$u -> nd_%3$u\n"
        ,exp_idx,exp_ptr[2],exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      exp_stack.push(exp_ptr[3]);
      break;
    case c_node_type_operator_binary_exclamation_equal:
      _printf_p(
        "   nd_%1$u [ label = \"operator_binary_exclamation_equal\" ]\n"
        "   nd_%1$u -> nd_%2$u\n"
        "   nd_%1$u -> nd_%3$u\n"
        ,exp_idx,exp_ptr[2],exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      exp_stack.push(exp_ptr[3]);
      break;
    case c_node_type_operator_binary_rs_br:
      _printf_p(
        "   nd_%1$u [ label = \"operator_binary_rs_br\" ]\n"
        "   nd_%1$u -> nd_%2$u\n"
        "   nd_%1$u -> nd_%3$u\n"
        ,exp_idx,exp_ptr[2],exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      exp_stack.push(exp_ptr[3]);
      break;
    case c_node_type_operator_binary_ls_br:
      _printf_p(
        "   nd_%1$u [ label = \"operator_binary_ls_br\" ]\n"
        "   nd_%1$u -> nd_%2$u\n"
        "   nd_%1$u -> nd_%3$u\n"
        ,exp_idx,exp_ptr[2],exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      exp_stack.push(exp_ptr[3]);
      break;
    case c_node_type_operator_binary_rs_br_equal:
      _printf_p(
        "   nd_%1$u [ label = \"operator_binary_rs_br_equal\" ]\n"
        "   nd_%1$u -> nd_%2$u\n"
        "   nd_%1$u -> nd_%3$u\n"
        ,exp_idx,exp_ptr[2],exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      exp_stack.push(exp_ptr[3]);
      break;
    case c_node_type_operator_binary_ls_br_equal:
      _printf_p(
        "   nd_%1$u [ label = \"operator_binary_ls_br_equal\" ]\n"
        "   nd_%1$u -> nd_%2$u\n"
        "   nd_%1$u -> nd_%3$u\n"
        ,exp_idx,exp_ptr[2],exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      exp_stack.push(exp_ptr[3]);
      break;
    case c_node_type_operator_binary_double_rs_br:
      _printf_p(
        "   nd_%1$u [ label = \"operator_binary_double_rs_br\" ]\n"
        "   nd_%1$u -> nd_%2$u\n"
        "   nd_%1$u -> nd_%3$u\n"
        ,exp_idx,exp_ptr[2],exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      exp_stack.push(exp_ptr[3]);
      break;
    case c_node_type_operator_binary_double_ls_br:
      _printf_p(
        "   nd_%1$u [ label = \"operator_binary_double_ls_br\" ]\n"
        "   nd_%1$u -> nd_%2$u\n"
        "   nd_%1$u -> nd_%3$u\n"
        ,exp_idx,exp_ptr[2],exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      exp_stack.push(exp_ptr[3]);
      break;
    case c_node_type_operator_binary_plus:
      _printf_p(
        "   nd_%1$u [ label = \"operator_binary_plus\" ]\n"
        "   nd_%1$u -> nd_%2$u\n"
        "   nd_%1$u -> nd_%3$u\n"
        ,exp_idx,exp_ptr[2],exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      exp_stack.push(exp_ptr[3]);
      break;
    case c_node_type_operator_binary_minus:
      _printf_p(
        "   nd_%1$u [ label = \"operator_binary_minus\" ]\n"
        "   nd_%1$u -> nd_%2$u\n"
        "   nd_%1$u -> nd_%3$u\n"
        ,exp_idx,exp_ptr[2],exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      exp_stack.push(exp_ptr[3]);
      break;
    case c_node_type_operator_binary_asterisk:
      _printf_p(
        "   nd_%1$u [ label = \"operator_binary_asterisk\" ]\n"
        "   nd_%1$u -> nd_%2$u\n"
        "   nd_%1$u -> nd_%3$u\n"
        ,exp_idx,exp_ptr[2],exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      exp_stack.push(exp_ptr[3]);
      break;
    case c_node_type_operator_binary_slash:
      _printf_p(
        "   nd_%1$u [ label = \"operator_binary_slash\" ]\n"
        "   nd_%1$u -> nd_%2$u\n"
        "   nd_%1$u -> nd_%3$u\n"
        ,exp_idx,exp_ptr[2],exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      exp_stack.push(exp_ptr[3]);
      break;
    case c_node_type_operator_binary_percent:
      _printf_p(
        "   nd_%1$u [ label = \"operator_binary_percent\" ]\n"
        "   nd_%1$u -> nd_%2$u\n"
        "   nd_%1$u -> nd_%3$u\n"
        ,exp_idx,exp_ptr[2],exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      exp_stack.push(exp_ptr[3]);
      break;
    case c_node_type_operator_unary_post_double_plus:
      _printf_p(
        "   nd_%1$u [ label = \"operator_unary_post_double_plus\" ]\n"
        "   nd_%1$u -> nd_%2$u\n"
        ,exp_idx,exp_ptr[2]);
      exp_stack.push(exp_ptr[2]);
      break;
    case c_node_type_operator_unary_post_double_minus:
      _printf_p(
        "   nd_%1$u [ label = \"operator_unary_post_double_minus\" ]\n"
        "   nd_%1$u -> nd_%2$u\n"
        ,exp_idx,exp_ptr[2]);
      exp_stack.push(exp_ptr[2]);
      break;
    case c_node_type_operator_unary_pre_double_plus:
      _printf_p(
        "   nd_%1$u [ label = \"operator_unary_pre_double_plus\" ]\n"
        "   nd_%1$u -> nd_%2$u\n"
        ,exp_idx,exp_ptr[2]);
      exp_stack.push(exp_ptr[2]);
      break;
    case c_node_type_operator_unary_pre_double_minus:
      _printf_p(
        "   nd_%1$u [ label = \"operator_unary_pre_double_minus\" ]\n"
        "   nd_%1$u -> nd_%2$u\n"
        ,exp_idx,exp_ptr[2]);
      exp_stack.push(exp_ptr[2]);
      break;
    case c_node_type_operator_unary_pre_plus:
      _printf_p(
        "   nd_%1$u [ label = \"operator_unary_pre_plus\" ]\n"
        "   nd_%1$u -> nd_%2$u\n"
        ,exp_idx,exp_ptr[2]);
      exp_stack.push(exp_ptr[2]);
      break;
    case c_node_type_operator_unary_pre_minus:
      _printf_p(
        "   nd_%1$u [ label = \"operator_unary_pre_minus\" ]\n"
        "   nd_%1$u -> nd_%2$u\n"
        ,exp_idx,exp_ptr[2]);
      exp_stack.push(exp_ptr[2]);
      break;
    case c_node_type_operator_unary_pre_exclamation:
      _printf_p(
        "   nd_%1$u [ label = \"operator_unary_pre_exclamation\" ]\n"
        "   nd_%1$u -> nd_%2$u\n"
        ,exp_idx,exp_ptr[2]);
      exp_stack.push(exp_ptr[2]);
      break;
    case c_node_type_operator_unary_pre_tilde:
      _printf_p(
        "   nd_%1$u [ label = \"operator_unary_pre_tilde\" ]\n"
        "   nd_%1$u -> nd_%2$u\n"
        ,exp_idx,exp_ptr[2]);
      exp_stack.push(exp_ptr[2]);
      break;
    case c_node_type_operator_binary_le_br_re_br:
      _printf_p(
        "   nd_%1$u [ label = \"operator_binary_plus_equal\" ]\n"
        "   nd_%1$u -> nd_%2$u\n"
        "   nd_%1$u -> nd_%3$u\n"
        ,exp_idx,exp_ptr[2],exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      exp_stack.push(exp_ptr[3]);
      break;
    case c_node_type_identifier:
      printf("   nd_%u [ label = \"identifier: %s\" ]\n",exp_idx,variable_symbol_names[exp_ptr[2]].data);
      break;
    case c_node_type_element_identifier:
      printf("   nd_%u [ label = \"element_identifier: %s\" ]\n",exp_idx,variable_symbol_names[exp_ptr[2]].data);
      break;
    case c_node_type_this_access:
      printf("   nd_%u [ label = \"this_acces\" ]\n",exp_idx);
      break;
    case c_node_type_new_object:
    {
      printf("   nd_%u [ label = \"new_object\" ]\n",exp_idx);

      printf("   nd_%u -> nd_%u\n",exp_idx,exp_ptr[3]);
      exp_stack.push(exp_ptr[3]);

      unsigned parm_cnt = exp_ptr[2];

      if (parm_cnt != 0)
      {
        unsigned parm_idx = parm_cnt;
        do
        {
          parm_idx--;

          printf("   nd_%u -> nd_%u\n",exp_idx,exp_ptr[parm_idx + 4]);
          exp_stack.push(exp_ptr[parm_idx + 4]);
        }
        while(parm_idx > 0);
      }
    }
    break;
    case c_node_type_new_objects_array:
      _printf_p(
        "   nd_%1$u [ label = \"new_objects_array\" ]\n"
        "   nd_%1$u -> nd_%2$u\n"
        "   nd_%1$u -> nd_%3$u\n"
        ,exp_idx,exp_ptr[2],exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      exp_stack.push(exp_ptr[3]);
      break;
    case c_node_type_free_object:
      _printf_p(
        "   nd_%1$u [ label = \"free_object\" ]\n"
        "   nd_%1$u -> nd_%2$u\n"
        ,exp_idx,exp_ptr[2]);
      exp_stack.push(exp_ptr[2]);
      break;
    case c_node_type_type_identification:
      _printf_p(
        "   nd_%1$u [ label = \"type_identification\" ]\n"
        "   nd_%1$u -> nd_%2$u\n"
        ,exp_idx,exp_ptr[1]);
      exp_stack.push(exp_ptr[1]);
      break;
    case c_node_type_object_reference_copy:
      _printf_p(
        "   nd_%1$u [ label = \"object_reference_copy\" ]\n"
        "   nd_%1$u -> nd_%2$u\n"
        "   nd_%1$u -> nd_%3$u\n"
        ,exp_idx,exp_ptr[1],exp_ptr[2]);
      exp_stack.push(exp_ptr[1]);
      exp_stack.push(exp_ptr[2]);
      break;
    case c_node_type_conditional_expression:
      _printf_p(
        "   nd_%1$u [ label = \"conditional_expression\" ]\n"
        "   nd_%1$u -> nd_%2$u\n"
        "   nd_%1$u -> nd_%3$u\n"
        "   nd_%1$u -> nd_%4$u\n"
        ,exp_idx,exp_ptr[2],exp_ptr[3],exp_ptr[4]);
      exp_stack.push(exp_ptr[2]);
      exp_stack.push(exp_ptr[3]);
      exp_stack.push(exp_ptr[4]);
      break;
    case c_node_type_logical_and:
      _printf_p(
        "   nd_%1$u [ label = \"logical_and\" ]\n"
        "   nd_%1$u -> nd_%2$u\n"
        "   nd_%1$u -> nd_%3$u\n"
        ,exp_idx,exp_ptr[2],exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      exp_stack.push(exp_ptr[3]);
      break;
    case c_node_type_logical_or:
      _printf_p(
        "   nd_%1$u [ label = \"logical_or\" ]\n"
        "   nd_%1$u -> nd_%2$u\n"
        "   nd_%1$u -> nd_%3$u\n"
        ,exp_idx,exp_ptr[2],exp_ptr[3]);
      exp_stack.push(exp_ptr[2]);
      exp_stack.push(exp_ptr[3]);
      break;
    case c_node_type_class_access:
    {
      printf(
        "   nd_%u [ label = \"class_access",exp_idx);

      unsigned name_cnt = exp_ptr[2];

      if (name_cnt != 0)
      {
        unsigned *ni_ptr = exp_ptr + 3;
        unsigned *ni_ptr_end = ni_ptr + name_cnt;
        do {
          printf(" %s",class_symbol_names[*ni_ptr].data);

          if (++ni_ptr >= ni_ptr_end)
            break;

          printf(",");
        } while(true);
      }

      printf("\" ]\n");
    }
    break;
    case c_node_type_object_member_select:
      _printf_p(
        "   nd_%1$u [ label = \"object_member_select: %2$s\" ]\n"
        "   nd_%1$u -> nd_%3$u\n"
        ,exp_idx,variable_symbol_names[exp_ptr[2]].data,exp_ptr[3]);
      exp_stack.push(exp_ptr[3]);
      break;
    case c_node_type_this_method_call:
    {
      printf("   nd_%u [ label = \"this_method_call: %s\" ]\n",exp_idx,method_symbol_names[exp_ptr[2]].data);

      unsigned parm_cnt = exp_ptr[3];

      if (parm_cnt != 0)
      {
        unsigned parm_idx = 0;
        do
        {
          printf("   nd_%u -> nd_%u\n",exp_idx,exp_ptr[parm_idx + 4]);
          exp_stack.push(exp_ptr[parm_idx + 4]);
        }
        while(++parm_idx < parm_cnt);
      }
    }
    break;
    case c_node_type_object_method_call:
    {
      printf("   nd_%u [ label = \"object_method_call: %s\" ]\n",exp_idx,method_symbol_names[exp_ptr[2]].data);

      unsigned parm_cnt = exp_ptr[3] + 1;
      unsigned parm_idx = 0;

      do
      {
        printf("   nd_%u -> nd_%u\n",exp_idx,exp_ptr[parm_idx + 4]);
        exp_stack.push(exp_ptr[parm_idx + 4]);
      }
      while(++parm_idx < parm_cnt);
    }
    break;
    case c_node_type_const_char:
      printf("   nd_%u [ label = \"const: '%c'\" ]\n",exp_idx,const_chars[exp_ptr[1]]);
      break;
    case c_node_type_const_int:
      printf("   nd_%u [ label = \"const: %" HOST_LL_FORMAT "d\" ]\n",exp_idx,const_ints[exp_ptr[1]]);
      break;
    case c_node_type_const_float:
      printf("   nd_%u [ label = \"const: %f\" ]\n",exp_idx,const_floats[exp_ptr[1]]);
      break;
    case c_node_type_const_string:
      printf("   nd_%u [ label = \"const: \\\"%s\\\"\" ]\n",exp_idx,const_strings[exp_ptr[1]].data);
      break;
    case c_node_type_const_delegate:
      printf("   nd_%u [ label = \"const: lambda function\" ]\n",exp_idx);
      break;
    default:
      cassert(0);
    }

  }
  while(exp_stack.used > 0);

  exp_stack.clear();

  printf("}\n");
}/*}}}*/

void script_parser_s::DEBUG_show_dot_format_method_expressions()
{/*{{{*/
  if (method_flow_graphs.used == 0) return;

  unsigned mfg_idx = 0;
  do
  {
    exp_flow_graph_s &method_flow_graph = method_flow_graphs[mfg_idx];
    ui_array_s &fg_nodes = method_flow_graph.nodes;

    unsigned *fg_data = fg_nodes.data;
    unsigned fg_idx = 0;

    // - cycle through nodes of program flow graph -
    do
    {
      unsigned *fg_ptr = fg_data + fg_idx;

      switch(*fg_ptr)
      {
      case c_fg_type_expression:
        DEBUG_show_dot_format_expression(method_flow_graph.expressions[fg_ptr[c_fg_expression_idx]]);
        fg_idx += c_fg_expression_size;
        break;
      case c_fg_type_condition:
        DEBUG_show_dot_format_expression(method_flow_graph.expressions[fg_ptr[c_fg_expression_idx]]);
        fg_idx += c_fg_condition_size;
        break;
      case c_fg_type_return_expression:
        DEBUG_show_dot_format_expression(method_flow_graph.expressions[fg_ptr[c_fg_expression_idx]]);
        fg_idx += c_fg_return_expression_size;
        break;
      case c_fg_type_for_loop:
        DEBUG_show_dot_format_expression(method_flow_graph.expressions[fg_ptr[c_fg_expression_idx]]);
        fg_idx += c_fg_for_loop_size;
        break;
      case c_fg_type_break:
        fg_idx += c_fg_break_size;
        break;
      case c_fg_type_continue:
        fg_idx += c_fg_continue_size;
        break;
      case c_fg_type_switch:
        DEBUG_show_dot_format_expression(method_flow_graph.expressions[fg_ptr[c_fg_expression_idx]]);
        fg_idx += c_fg_switch_size + fg_ptr[c_fg_switch_default_cnt] + fg_ptr[c_fg_switch_exp_cnt];
        break;
      default:
        cassert(0);
      }
    }
    while(fg_idx < fg_nodes.used);
  }
  while(++mfg_idx < method_flow_graphs.used);
}/*}}}*/

void script_parser_s::DEBUG_show_dot_format_init_expressions()
{/*{{{*/
  if (init_expressions.used == 0) return;

  unsigned ie_idx = 0;
  do
  {
    DEBUG_show_dot_format_expression(init_expressions[ie_idx]);
  }
  while(++ie_idx < init_expressions.used);
}/*}}}*/

void script_parser_s::DEBUG_show_dot_format_flow_graph(exp_flow_graph_s &fg)
{/*{{{*/

  ui_array_s &fg_nodes = fg.nodes;
  if (fg_nodes.used == 0) return;

  printf(
    "// ## DOT FLOW GRAPH ##\n"
    "digraph G {\n"
    "   rankdir=LR\n"
    "   ordering=in\n"
    "\n"
    "   overlap=false\n"
    "   graph [fontsize=12]\n"
    "   edge [fontsize=12]\n"
    "   node [shape=plaintext fontsize=12]\n"
    "\n"
  );

  unsigned *fg_data = fg_nodes.data;
  unsigned fg_idx = 0;

  // - output node description and edges between them -
  do
  {
    unsigned *fg_ptr = fg_data + fg_idx;

    switch(*fg_ptr)
    {
    case c_fg_type_expression:
      printf("   node_%u [ label = \"Expression\" ]\n",fg_idx);

      if (fg_ptr[c_fg_expression_first_out] != c_idx_not_exist)
      {
        printf("   node_%u -> node_%u\n",fg_idx,fg_ptr[c_fg_expression_first_out]);
      }

      fg_idx += c_fg_expression_size;
      break;
    case c_fg_type_condition:
      printf("   node_%u [ label = \"Condition\" ]\n",fg_idx);

      if (fg_ptr[c_fg_condition_first_out] != c_idx_not_exist)
      {
        printf("   node_%u -> node_%u [ label = \"true\" color = green ]\n",fg_idx,fg_ptr[c_fg_condition_first_out]);
      }

      if (fg_ptr[c_fg_condition_second_out] != c_idx_not_exist)
      {
        printf("   node_%u -> node_%u [ label = \"false\" ]\n",fg_idx,fg_ptr[c_fg_condition_second_out]);
      }

      fg_idx += c_fg_condition_size;
      break;
    case c_fg_type_return_expression:
      printf("   node_%u [ label = \"Return\" ]\n",fg_idx);

      fg_idx += c_fg_return_expression_size;
      break;
    case c_fg_type_for_loop:
      printf("   node_%u [ label = \"For loop\" ]\n",fg_idx);

      if (fg_ptr[c_fg_for_loop_body] != c_idx_not_exist)
      {
        printf("   node_%u -> node_%u [ label = \"body\" ]\n",fg_idx,fg_ptr[c_fg_for_loop_body]);
      }

      if (fg_ptr[c_fg_expression_first_out] != c_idx_not_exist)
      {
        printf("   node_%u -> node_%u [ label = \"done\" ]\n",fg_idx,fg_ptr[c_fg_expression_first_out]);
      }

      fg_idx += c_fg_for_loop_size;
      break;
    case c_fg_type_break:
      printf("   node_%u [ label = \"Break\" ]\n",fg_idx);

      fg_idx += c_fg_break_size;
      break;
    case c_fg_type_continue:
      printf("   node_%u [ label = \"Continue\" ]\n",fg_idx);

      fg_idx += c_fg_continue_size;
      break;
    case c_fg_type_switch:
    {
      printf("   node_%u [ label = \"Switch\" ]\n",fg_idx);

      unsigned *c_ptr = fg_ptr + c_fg_switch_defaults;

      if (fg_ptr[c_fg_switch_default_cnt] > 0)
      {
        unsigned *c_ptr_end = fg_ptr + c_fg_switch_defaults + fg_ptr[c_fg_switch_default_cnt];
        do
        {
          if (*c_ptr != c_idx_not_exist)
          {
            printf("   node_%u -> node_%u [ label = \"default\" ]\n",fg_idx,*c_ptr);
          }
        }
        while(++c_ptr < c_ptr_end);
      }

      if (fg_ptr[c_fg_switch_exp_cnt] > 0)
      {
        unsigned *c_ptr_end = c_ptr + fg_ptr[c_fg_switch_exp_cnt];
        unsigned last_c_idx = c_idx_not_exist;
        unsigned e_idx = 0;

        do
        {
          if (*c_ptr != c_idx_not_exist)
          {
            printf("   node_%u -> node_%u [ label = \"",fg_idx,*c_ptr);
            last_c_idx = *c_ptr;

            do
            {
              printf("%u,",e_idx++);
            }
            while(++c_ptr < c_ptr_end && *c_ptr == last_c_idx);

            printf("\" ]\n");
          }
          else
          {
            e_idx++;
            c_ptr++;
          }
        }
        while(c_ptr < c_ptr_end);
      }

      if (fg_ptr[c_fg_expression_first_out] != c_idx_not_exist)
      {
        printf("   node_%u -> node_%u [ label = \"done\" ]\n",fg_idx,fg_ptr[c_fg_expression_first_out]);
      }

      fg_idx += c_fg_switch_size + fg_ptr[c_fg_switch_default_cnt] + fg_ptr[c_fg_switch_exp_cnt];
    }
    break;
    default:
      cassert(0);
    }

  }
  while(fg_idx < fg_nodes.used);

  printf("}\n");
}/*}}}*/

void script_parser_s::DEBUG_show_dot_format_method_flow_graphs()
{/*{{{*/
  if (method_flow_graphs.used == 0) return;

  unsigned mfg_idx = 0;
  do
  {
    DEBUG_show_dot_format_flow_graph(method_flow_graphs[mfg_idx]);
  }
  while(++mfg_idx < method_flow_graphs.used);
}/*}}}*/

void script_parser_s::DEBUG_show_dot_format_class_inheritance()
{/*{{{*/
  printf(
    "// ## DOT CLASS INHERITANCE TREE ##\n"
    "digraph G {\n"
    "   rankdir=TD;\n"
    "   node [shape=ellipse];\n"
  );

  if (class_records.used != 0)
  {
    unsigned cl_idx = 0;
    do {
      class_record_s &class_record = class_records[cl_idx];
      string_s &class_name = class_symbol_names[class_record.name_idx];

      printf("   nd_%u [ label = \"%s\" ]\n",cl_idx,class_name.data);

      if (class_record.extend_class_idx != c_idx_not_exist)
      {
        printf("   nd_%u -> nd_%u\n",class_record.extend_class_idx,cl_idx);
      }
    } while(++cl_idx < class_records.used);
  }

  printf("}\n");
}/*}}}*/

void script_parser_s::DEBUG_print_instruction(uli **pptr)
{/*{{{*/
  switch (*(*pptr))
  {
  case i_this_element:
    printf("%lu: i_this_element: %lu <- element: %s\n",(*pptr)[ite_source_pos],(*pptr)[ite_stack_trg],variable_symbol_names[(*pptr)[ite_name_idx]].data);
    (*pptr) += ite_size;
    break;
  case i_const:
    printf("i_const: %lu <- const: %lu\n",(*pptr)[ic_stack_trg],(*pptr)[ic_const_idx]);
    (*pptr) += ic_size;
    break;
  case i_static:
    printf("%lu: i_static: %lu <- static: %lu\n",(*pptr)[is_source_pos],(*pptr)[is_stack_trg],(*pptr)[is_element_pos]);
    (*pptr) += is_size;
    break;
  case i_call:
  {
    printf("%lu: i_call: %lu <- %s params: ",(*pptr)[icl_source_pos],(*pptr)[icl_stack_trg],method_symbol_names[(*pptr)[icl_name_idx]].data);

    uli *p_ptr = (*pptr) + icl_parm_this;
    uli *p_ptr_end = p_ptr + (*pptr)[icl_parm_cnt];
    do
    {
      printf("%lu,",*p_ptr);
    }
    while(++p_ptr < p_ptr_end);

    putchar('\n');
    (*pptr) += icl_size + (*pptr)[icl_parm_cnt];
  }
  break;
  case i_static_call:
  {
    printf("%lu: i_static_call: %lu <- mr_idx: %lu params: ",(*pptr)[iscl_source_pos],(*pptr)[iscl_stack_trg],(*pptr)[iscl_method_ri]);

    uli *p_ptr = (*pptr) + iscl_parm_first;
    uli *p_ptr_end = p_ptr + (*pptr)[iscl_parm_cnt];
    do
    {
      printf("%lu,",*p_ptr);
    }
    while(++p_ptr < p_ptr_end);

    putchar('\n');
    (*pptr) += iscl_size + (*pptr)[iscl_parm_cnt];
  }
  break;
  case i_element_array:
    printf("%lu: i_element_array: %lu <- ",(*pptr)[iea_source_pos],(*pptr)[iea_stack_trg]);

    if ((*pptr)[iea_element_cnt] != 0)
    {
      uli *e_ptr = (*pptr) + iea_element_first;
      uli *e_ptr_end = e_ptr + (*pptr)[iea_element_cnt];
      do
      {
        printf("%lu,",*e_ptr);
      }
      while(++e_ptr < e_ptr_end);
    }

    putchar('\n');
    (*pptr) += iea_size + (*pptr)[iea_element_cnt];
    break;
  case i_new_object:
  {
    printf("%lu: i_new_object: %lu <- class: %s constructor: %s params: ",(*pptr)[ino_source_pos],(*pptr)[ino_stack_trg],class_symbol_names[class_records[(*pptr)[ino_class_ri]].name_idx].data,method_symbol_names[(*pptr)[ino_constr_name]].data);

    uli *p_ptr = (*pptr) + ino_parm_first;
    uli *p_ptr_end = p_ptr + (*pptr)[ino_parm_cnt];
    do
    {
      printf("%lu,",*p_ptr);
    }
    while(++p_ptr < p_ptr_end);

    putchar('\n');
    (*pptr) += ino_size + (*pptr)[ino_parm_cnt];
  }
  break;
  case i_new_objects_array:
    printf("%lu: i_new_objects_array: %lu <- class: %s constructor: %s count_pos: %lu\n",(*pptr)[inoa_source_pos],(*pptr)[inoa_stack_trg],class_symbol_names[class_records[(*pptr)[inoa_class_ri]].name_idx].data,method_symbol_names[(*pptr)[inoa_constr_name]].data,(*pptr)[inoa_stack_cnt]);
    (*pptr) += inoa_size;
    break;
  case i_free_object:
    printf("i_free_object: %lu <- %lu\n",(*pptr)[ifo_stack_trg],(*pptr)[ifo_stack_object]);
    (*pptr) += ifo_size;
    break;
  case i_type_identification:
    printf("i_type_identification: %lu <- %lu\n",(*pptr)[iti_stack_trg],(*pptr)[iti_stack_object]);
    (*pptr) += iti_size;
    break;
  case i_conditional_expression:
    printf("%lu: i_conditional_expression: %lu <- %lu\n",(*pptr)[ice_source_pos],(*pptr)[ice_stack_trg],(*pptr)[ice_stack_src]);
    (*pptr) += (*pptr)[ice_end];
    break;
  case i_logical_and:
    printf("%lu: i_logical_and: %lu <- %lu\n",(*pptr)[ila_source_pos],(*pptr)[ila_stack_trg],(*pptr)[ila_stack_src]);
    (*pptr) += (*pptr)[ila_end];
    break;
  case i_logical_or:
    printf("%lu: i_logical_or: %lu <- %lu\n",(*pptr)[ilo_source_pos],(*pptr)[ilo_stack_trg],(*pptr)[ilo_stack_src]);
    (*pptr) += (*pptr)[ilo_end];
    break;
  case i_object_reference_copy:
    printf("i_object_reference_copy: %lu <- operands: %lu,%lu\n",(*pptr)[iorc_stack_trg],(*pptr)[iorc_stack_dst],(*pptr)[iorc_stack_src]);
    (*pptr) += iorc_size;
    break;
  case i_object_member_select:
    printf("%lu: i_object_member_select: %lu <- element: %s %lu\n",(*pptr)[ioms_source_pos],(*pptr)[ioms_stack_trg],variable_symbol_names[(*pptr)[ioms_var_name]].data,(*pptr)[ioms_stack_object]);
    (*pptr) += ioms_size;
    break;
  case i_switch_test:
    printf("%lu: i_switch_test: %lu <- ",(*pptr)[ist_source_pos],(*pptr)[ist_stack_trg]);

    if ((*pptr)[ist_value_cnt] != 0)
    {
      uli *e_ptr = (*pptr) + ist_value_first;
      uli *e_ptr_end = e_ptr + (*pptr)[ist_value_cnt];
      do
      {
        printf("%lu,",*e_ptr);
      }
      while(++e_ptr < e_ptr_end);
    }

    putchar('\n');
    (*pptr) += ist_size + (*pptr)[ist_value_cnt];
    break;
  case i_slice_range:
    printf("%lu: i_slice_range: %lu <- %lu slice: %lu,%lu,%lu\n",(*pptr)[isr_source_pos],(*pptr)[isr_stack_trg],(*pptr)[isr_stack_src],(*pptr)[isr_start],(*pptr)[isr_stop],(*pptr)[isr_step]);
    (*pptr) += isr_size;
    break;
  case i_expression_end:
    printf("i_expression_end\n");
    (*pptr) += iee_size;
    break;
  case i_return:
    printf("i_return: %lu ->\n",(*pptr)[ir_stack_pos]);
    (*pptr) += ir_size;
    break;
  default:
    cassert(0);
  }
}/*}}}*/

void script_parser_s::DEBUG_show_static_im_code()
{/*{{{*/
  if (static_begin_code.used != 0)
  {
    printf(" -- static_begin_code -- \n");

    uli *ptr = static_begin_code.data;
    uli *ptr_end = ptr + static_begin_code.used;

    do
    {
      DEBUG_print_instruction(&ptr);
    }
    while(ptr < ptr_end);
  }

  if (static_run_time_code.used != 0)
  {
    printf(" -- static_run_time_code -- \n");

    uli *ptr = static_run_time_code.data;
    uli *ptr_end = ptr + static_run_time_code.used;

    do
    {
      DEBUG_print_instruction(&ptr);
    }
    while(ptr < ptr_end);
  }
}/*}}}*/

void script_parser_s::DEBUG_show_class_im_codes()
{/*{{{*/
  unsigned c_idx = 0;
  do
  {
    class_record_s &class_record = class_records[c_idx];
    if (!(class_record.modifiers & c_modifier_built_in))
    {
      printf(" XXXXXXXXXXXXXXXXXX CLASS: %s XXXXXXXXXXXXXXXXXX  \n",class_symbol_names[class_record.name_idx].data);

      uli_array_s &init_begin_code = class_record.init_begin_code;
      if (init_begin_code.used != 0)
      {
        printf(" -- init_begin_code -- \n");

        uli *ptr = init_begin_code.data;
        uli *ptr_end = ptr + init_begin_code.used;

        do
        {
          DEBUG_print_instruction(&ptr);
        }
        while(ptr < ptr_end);
      }

      uli_array_s &init_run_time_code = class_record.init_run_time_code;
      if (init_run_time_code.used != 0)
      {
        printf(" -- init_run_time_code -- \n");

        uli *ptr = init_run_time_code.data;
        uli *ptr_end = ptr + init_run_time_code.used;

        do
        {
          DEBUG_print_instruction(&ptr);
        }
        while(ptr < ptr_end);
      }
    }
  }
  while(++c_idx < class_records.used);
}/*}}}*/

void script_parser_s::DEBUG_show_method_im_codes()
{/*{{{*/
  if (method_records.used == 0) return;

  unsigned m_idx = 0;
  do
  {
    method_record_s &method_record = method_records[m_idx];

    if (!(method_record.modifiers & c_modifier_abstract))
    {
      if (method_record.name_idx != c_idx_not_exist)
      {
        printf(" XXXXXXXXXXXXXXXXXX METHOD: %s::%s XXXXXXXXXXXXXXXXXX \n",class_symbol_names[class_records[method_record.parent_record].name_idx].data,
            method_symbol_names[method_record.name_idx].data);
      }
      else
      {
        printf(" XXXXXXXXXXXXXXXXXX METHOD: %s::<anon_%u> XXXXXXXXXXXXXXXXXX \n",
            method_record.parent_record == c_idx_not_exist ? "<none>" : class_symbol_names[class_records[method_record.parent_record].name_idx].data,
            m_idx);
      }

      uli_array_s &begin_code = method_record.begin_code;
      uli_array_s &run_time_code = method_record.run_time_code;

      if (begin_code.used != 0)
      {
        printf("-- begin_code --\n");

        uli *ptr = begin_code.data;
        uli *ptr_end = ptr + begin_code.used;

        do
        {
          DEBUG_print_instruction(&ptr);
        }
        while(ptr < ptr_end);
      }

      if (run_time_code.used != 0)
      {
        printf("-- run_time_code --\n");

        uli *ptr = run_time_code.data;
        uli *ptr_end = ptr + run_time_code.used;

        do
        {
          DEBUG_print_instruction(&ptr);
        }
        while(ptr < ptr_end);
      }
    }
  }
  while(++m_idx < method_records.used);
}/*}}}*/

void script_parser_s::DEBUG_gen_ucl_description(FILE *a_file)
{/*{{{*/
  const char *c_comma[2] = {
    "",
    ","
  };

#define GEN_UCL_NAME_POS(BUFF_NAME,VAR_NAME,POINTER) \
/*{{{*/\
char BUFF_NAME[32];\
char *VAR_NAME;\
{\
  unsigned &sym_pos_start = (POINTER)->name_position.ui_first;\
  unsigned &sym_pos_end = (POINTER)->name_position.ui_second;\
\
  if (sym_pos_start != c_idx_not_exist && sym_pos_end != c_idx_not_exist)\
  {\
    snprintf(BUFF_NAME,32,"%u,%u,%u",\
      GET_SRC_IDX(sym_pos_start),\
      GET_SRC_POS(sym_pos_start),\
      GET_SRC_POS(sym_pos_end));\
\
    VAR_NAME = BUFF_NAME;\
  }\
  else\
  {\
    VAR_NAME = (char *)"B,B,B";\
  }\
}/*}}}*/

#define GEN_UCL_INDEX_REF_NOBI(BUFF_NAME,VAR_NAME,POINTER,VALUE) \
/*{{{*/\
char BUFF_NAME[16];\
char *VAR_NAME;\
{\
  if (((POINTER)->modifiers & c_modifier_built_in) || (VALUE) == c_idx_not_exist)\
  {\
    VAR_NAME = (char *)"B";\
  }\
  else\
  {\
    snprintf(BUFF_NAME,16,"%u",(VALUE));\
\
    VAR_NAME = BUFF_NAME;\
  }\
}/*}}}*/

#define GEN_UCL_INDEX_ARRAY(ARRAY) \
{/*{{{*/\
  if ((ARRAY).used != 0)\
  {\
    unsigned *ptr = (ARRAY).data;\
    unsigned *ptr_end = ptr + (ARRAY).used;\
    do {\
      fprintf(a_file,"%u%s",*ptr,c_comma[ptr_end - ptr > 1]);\
    } while(++ptr < ptr_end);\
  }\
}/*}}}*/

#define GEN_UCL_INDEX_ARRAY_INX(ARRAY) \
{/*{{{*/\
  if ((ARRAY).used != 0)\
  {\
    unsigned *ptr = (ARRAY).data;\
    unsigned *ptr_end = ptr + (ARRAY).used;\
    do {\
      if (*ptr != c_idx_not_exist)\
      {\
        fprintf(a_file,"%u%s",*ptr,c_comma[ptr_end - ptr > 1]);\
      }\
      else\
      {\
        fprintf(a_file,"B%s",c_comma[ptr_end - ptr > 1]);\
      }\
    } while(++ptr < ptr_end);\
  }\
}/*}}}*/

  fprintf(a_file,
"\n"
"class Variable\n"
"{/*{{{*/\n"
"  static private idx_cnt = 0;\n"
"\n"
"  public m_idx = idx_cnt++;\n"
"  public m_name;\n"
"  public m_full_name;\n"
"  public m_modifiers;\n"
"  public m_parent_record;\n"
"  public m_init_expression_idx;\n"
"  public m_source_idx;\n"
"  public m_pos_start;\n"
"  public m_pos_end;\n"
"  public m_comment;\n"
"\n"
"  public Variable(a_name,a_modifiers,a_parent_record,a_init_expression_idx,a_source_idx,a_pos_start,a_pos_end)\n"
"  {\n"
"    m_name = a_name;\n"
"    m_full_name = Data.B;\n"
"    m_modifiers = a_modifiers;\n"
"    m_parent_record = a_parent_record;\n"
"    m_init_expression_idx = a_init_expression_idx;\n"
"    m_source_idx = a_source_idx;\n"
"    m_pos_start = a_pos_start;\n"
"    m_pos_end = a_pos_end;\n"
"    m_comment = Data.B;\n"
"  }\n"
"}/*}}}*/\n"
"\n"
  );

  fprintf(a_file,
"class Method\n"
"{/*{{{*/\n"
"  static private idx_cnt = 0;\n"
"\n"
"  public m_idx = idx_cnt++;\n"
"  public m_name;\n"
"  public m_full_name;\n"
"  public m_modifiers;\n"
"  public m_parent_record;\n"
"  public m_parameter_idxs;\n"
"  public m_flow_graph_idx;\n"
"  public m_source_idx;\n"
"  public m_pos_start;\n"
"  public m_pos_end;\n"
"  public m_comment;\n"
"\n"
"  public Method(a_name,a_modifiers,a_parent_record,a_parameter_idxs,a_flow_graph_idx,a_source_idx,a_pos_start,a_pos_end)\n"
"  {\n"
"    m_name = a_name;\n"
"    m_full_name = Data.B;\n"
"    m_modifiers = a_modifiers;\n"
"    m_parent_record = a_parent_record;\n"
"    m_parameter_idxs = a_parameter_idxs;\n"
"    m_flow_graph_idx = a_flow_graph_idx;\n"
"    m_source_idx = a_source_idx;\n"
"    m_pos_start = a_pos_start;\n"
"    m_pos_end = a_pos_end;\n"
"    m_comment = Data.B;\n"
"  }\n"
"}/*}}}*/\n"
"\n"
  );

  fprintf(a_file,
"class Class\n"
"{/*{{{*/\n"
"  static private idx_cnt = 0;\n"
"\n"
"  public m_idx = idx_cnt++;\n"
"  public m_name;\n"
"  public m_full_name;\n"
"  public m_modifiers;\n"
"  public m_parent_record;\n"
"  public m_extend_class_idx;\n"
"  public m_class_idxs;\n"
"  public m_method_idxs;\n"
"  public m_variable_idxs;\n"
"  public m_element_cnt;\n"
"  public m_extend_array;\n"
"  public m_source_idx;\n"
"  public m_pos_start;\n"
"  public m_pos_end;\n"
"  public m_comment;\n"
"\n"
"  public Class(a_name,a_modifiers,a_parent_record,a_extend_class_idx,a_class_idxs,a_method_idxs,a_variable_idxs,a_element_cn,a_extend_arra,a_source_idx,a_pos_start,a_pos_end)\n"
"  {\n"
"    m_name = a_name;\n"
"    m_full_name = Data.B;\n"
"    m_modifiers = a_modifiers;\n"
"    m_parent_record = a_parent_record;\n"
"    m_extend_class_idx = a_extend_class_idx;\n"
"    m_class_idxs = a_class_idxs;\n"
"    m_method_idxs = a_method_idxs;\n"
"    m_variable_idxs = a_variable_idxs;\n"
"    m_element_cnt = a_element_cnt;\n"
"    m_extend_array = a_extend_array;\n"
"    m_source_idx = a_source_idx;\n"
"    m_pos_start = a_pos_start;\n"
"    m_pos_end = a_pos_end;\n"
"    m_comment = Data.B;\n"
"  }\n"
"}/*}}}*/\n"
"\n"
  );

  fprintf(a_file,
"class Expression\n"
"{/*{{{*/\n"
"  public m_start_node_idx;\n"
"  public m_nodes;\n"
"\n"
"  public Expression(a_start_node_idx,a_nodes)\n"
"  {\n"
"    m_start_node_idx = a_start_node_idx;\n"
"    m_nodes = a_nodes;\n"
"  }\n"
"}/*}}}*/\n"
"\n"
  );

  fprintf(a_file,
"class FlowGraph\n"
"{/*{{{*/\n"
"  public m_start_node_idx;\n"
"  public m_nodes;\n"
"  public m_expressions;\n"
"\n"
"  public FlowGraph(a_start_node_idx,a_nodes,a_expressions)\n"
"  {\n"
"    m_start_node_idx = a_start_node_idx;\n"
"    m_nodes = a_nodes;\n"
"    m_expressions = a_expressions;\n"
"  }\n"
"}/*}}}*/\n"
"\n"
  );

  fprintf(a_file,
"class Data\n"
"{\n"
"  static public c_idx_not_exist = new Blank();\n"
"  static public B = c_idx_not_exist;\n"
"\n"
"  static public c_modifier_public       = 0x00000001;\n"
"  static public c_modifier_private      = 0x00000002;\n"
"  static public c_modifier_static       = 0x00000004;\n"
"  static public c_modifier_abstract     = 0x00000008;\n"
"  static public c_modifier_final        = 0x00000010;\n"
"  static public c_modifier_parallel     = 0x00000020;\n"
"  static public c_modifier_static_const = 0x00000040;\n"
"  static public c_modifier_built_in     = 0x00000080;\n"
"\n"
  );

  // - print sources -
  fprintf(a_file,
"  static public m_sources = [\n"
  );

  if (sources.used != 0)
  {
    source_s *s_ptr = sources.data;
    source_s *s_ptr_end = s_ptr + sources.used;
    do {
      fprintf(a_file,
"    \"%s\"%s\n"
      ,s_ptr->file_name.data,c_comma[s_ptr_end - s_ptr > 1]);
    } while(++s_ptr < s_ptr_end);

  }

  fprintf(a_file,
"  ];\n"
"\n"
  );

  // - print module names -
  fprintf(a_file,
"  static public m_module_names =\n"
"  [/*{{{*/\n"
  );

  if (module_names.used != 0)
  {
    string_s *s_ptr = module_names.data;
    string_s *s_ptr_end = s_ptr + module_names.used;
    do {
      fprintf(a_file,
"    \"%s\"%s\n"
      ,s_ptr->data,c_comma[s_ptr_end - s_ptr > 1]);
    } while(++s_ptr < s_ptr_end);
  }

  fprintf(a_file,
"  ];/*}}}*/\n"
"\n"
  );

  // - print variables -
  fprintf(a_file,
"  static public m_variables =\n"
"  [/*{{{*/\n"
  );

  if (variable_records.used != 0)
  {
    variable_record_s *vr_ptr = variable_records.data;
    variable_record_s *vr_ptr_end = vr_ptr + variable_records.used;
    do {
      GEN_UCL_INDEX_REF_NOBI(init_exp_buff,init_exp_str,vr_ptr,vr_ptr->init_expression_idx);
      GEN_UCL_NAME_POS(name_pos_buff,name_pos_str,vr_ptr);

      fprintf(a_file,
"    new Variable(\"%s\",%u,%u,%s,%s)%s\n"
      ,variable_symbol_names[vr_ptr->name_idx].data
      ,vr_ptr->modifiers
      ,vr_ptr->parent_record
      ,init_exp_str
      ,name_pos_str
      ,c_comma[vr_ptr_end - vr_ptr > 1]
      );

    } while(++vr_ptr < vr_ptr_end);
  }

  fprintf(a_file,
"  ];/*}}}*/\n"
"\n"
  );

  // - print methods -
  fprintf(a_file,
"  static public m_methods =\n"
"  [/*{{{*/\n"
  );

  if (method_records.used != 0)
  {
    method_record_s *mr_ptr = method_records.data;
    method_record_s *mr_ptr_end = mr_ptr + method_records.used;
    do {
      GEN_UCL_INDEX_REF_NOBI(flow_graph_buff,flow_graph_str,mr_ptr,mr_ptr->flow_graph_idx);
      GEN_UCL_NAME_POS(name_pos_buff,name_pos_str,mr_ptr);

      if (mr_ptr->name_idx != c_idx_not_exist)
      {
        fprintf(a_file,
"    new Method(\"%s\",%u,"
        ,method_symbol_names[mr_ptr->name_idx].data
        ,mr_ptr->modifiers);
      }
      else
      {
        fprintf(a_file,
"    new Method(\"<anon_%u>\",%u,"
        ,(unsigned)(mr_ptr - method_records.data)
        ,mr_ptr->modifiers);
      }

      if (mr_ptr->parent_record != c_idx_not_exist)
      {
        fprintf(a_file,"%u,["
            ,mr_ptr->parent_record);
      }
      else
      {
        fprintf(a_file,"B,[");
      }

      // - process indexes of method parameters -
      GEN_UCL_INDEX_ARRAY(mr_ptr->parameter_record_idxs);

      fprintf(a_file,"],%s,%s)%s\n"
        ,flow_graph_str
        ,name_pos_str
        ,c_comma[mr_ptr_end - mr_ptr > 1]);

    } while(++mr_ptr < mr_ptr_end);
  }

  fprintf(a_file,
"  ];/*}}}*/\n"
"\n"
  );

  // - print classes -
  fprintf(a_file,
"  static public m_classes =\n"
"  [/*{{{*/\n"
  );

  if (class_records.used != 0)
  {
    class_record_s *cr_ptr = class_records.data;
    class_record_s *cr_ptr_end = cr_ptr + class_records.used;
    do {
      GEN_UCL_INDEX_REF_NOBI(parent_record_buff,parent_record_str,cr_ptr,cr_ptr->parent_record);
      GEN_UCL_INDEX_REF_NOBI(extend_class_buff,extend_class_str,cr_ptr,cr_ptr->extend_class_idx);
      GEN_UCL_NAME_POS(name_pos_buff,name_pos_str,cr_ptr);

      fprintf(a_file,
"    new Class(\"%s\",%u,%s,%s,["
      ,class_symbol_names[cr_ptr->name_idx].data
      ,cr_ptr->modifiers
      ,parent_record_str
      ,extend_class_str);

      // - print class record indexes -
      GEN_UCL_INDEX_ARRAY(cr_ptr->class_record_idxs);
      fprintf(a_file,"],[");

      // - print method record indexes -
      GEN_UCL_INDEX_ARRAY(cr_ptr->method_record_idxs);
      fprintf(a_file,"],[");

      // - print variable record indexes -
      GEN_UCL_INDEX_ARRAY(cr_ptr->variable_record_idxs);
      fprintf(a_file,"],%u,[",cr_ptr->element_cnt);

      // - print extended record indexes -
      GEN_UCL_INDEX_ARRAY(cr_ptr->extend_array);

      fprintf(a_file,"],%s)%s\n"
        ,name_pos_str
        ,c_comma[cr_ptr_end - cr_ptr > 1]);

    } while(++cr_ptr < cr_ptr_end);
  }

  fprintf(a_file,
"  ];/*}}}*/\n"
"\n"
  );

  // - print flow graphs -
  fprintf(a_file,
"  static public m_flow_graphs =\n"
"  [/*{{{*/\n"
  );

  if (method_flow_graphs.used != 0)
  {
    exp_flow_graph_s *fg_ptr = method_flow_graphs.data;
    exp_flow_graph_s *fg_ptr_end = fg_ptr + method_flow_graphs.used;
    do {
      fprintf(a_file,
"    new FlowGraph(%u,["
      ,fg_ptr->start_node_idx);

      // - print flow graph nodes -
      GEN_UCL_INDEX_ARRAY_INX(fg_ptr->nodes);

      fprintf(a_file,"],\n"
"    [\n");

      // - print flow graph expressions -
      if (fg_ptr->expressions.used != 0)
      {
        expression_s *e_ptr = fg_ptr->expressions.data;
        expression_s *e_ptr_end = e_ptr + fg_ptr->expressions.used;
        do {
          fprintf(a_file,
"      new Expression(%u,["
          ,e_ptr->start_node_idx);

          // - print expression nodes -
          GEN_UCL_INDEX_ARRAY_INX(e_ptr->nodes);

          fprintf(a_file,"])%s\n"
          ,c_comma[e_ptr_end - e_ptr > 1]);

        } while(++e_ptr < e_ptr_end);
      }

      fprintf(a_file,
"    ])%s\n",c_comma[fg_ptr_end - fg_ptr > 1]);

    } while(++fg_ptr < fg_ptr_end);
  }

  fprintf(a_file,
"  ];/*}}}*/\n"
"\n"
  );

  fprintf(a_file,
"}\n"
"\n"
  );
}/*}}}*/

#endif

bool script_parser_s::import_module(built_in_module_s *a_module_ptr)
{/*{{{*/

  // - store module pointer -
  bi_module_pointers.push((pointer)a_module_ptr);

  // - set base of module exception identifiers -
  a_module_ptr->error_base = error_strings.used;

  // - if there are any exceptions defined in module -
  if (a_module_ptr->error_cnt != 0)
  {
    const char **es_ptr = a_module_ptr->error_strings;
    const char **es_ptr_end = es_ptr + a_module_ptr->error_cnt;
    do
    {
      error_strings.push_blank();
      error_strings.last().set(strlen(*es_ptr),*es_ptr);
    }
    while(++es_ptr < es_ptr_end);
  }

  // - if there are any classes defined in module -
  if (a_module_ptr->class_cnt != 0)
  {
    unsigned bic_idx = 0;
    do
    {
      built_in_class_s &built_in_class = *a_module_ptr->classes[bic_idx];

      // - get index of class name -
      unsigned class_name_idx = class_symbol_names.get_idx_char_ptr_insert(strlen(built_in_class.name),built_in_class.name);

      // - test uniqueness of built in class name -
      unsigned class_record_idx = get_parent_namespace_class_idx_by_name_idx(class_name_idx,parent_namespace_idxs.last());

      // - MODULE IMPORT ERROR -
      if (class_record_idx != c_idx_not_exist)
      {
        error_code.push(ei_module_duplicate_class_name);
        error_code.push(module_names_positions[module_idx].ui_first);
        error_code.push(class_name_idx);

        return false;
      }

      // - creation of new class record -
      class_records.push_blank();
      class_record_idx = class_records.used - 1;
      class_record_s &class_record = class_records[class_record_idx];

      // - insert class index to global namespace -
      namespace_records[0].class_record_idxs.push(class_record_idx);

      // - setting of class parameters -
      class_record.name_idx = class_name_idx;
      class_record.modifiers = built_in_class.modifiers | c_modifier_built_in;
      class_record.parent_record = c_idx_not_exist;
      class_record.extend_class_idx = c_idx_not_exist;

      // - save class name position in code -
      name_pos_s &name_position = class_record.name_position;
      name_position.ui_first = c_idx_not_exist;
      name_position.ui_second = c_idx_not_exist;

      // - initialize built in class pointer -
      class_record.bi_class_ptr = a_module_ptr->classes[bic_idx];

      if (built_in_class.method_cnt != 0)
      {
        unsigned bim_idx = 0;
        do
        {
          built_in_method_s &built_in_method = built_in_class.methods[bim_idx];

          // - get index of method name -
          unsigned method_name_idx = method_symbol_names.get_idx_char_ptr_insert(strlen(built_in_method.name),built_in_method.name);

          // - test uniqueness of method in parent class -
          ui_array_s &class_mr_idxs = class_record.method_record_idxs;

          if (class_mr_idxs.used != 0)
          {
            unsigned *mri_ptr = class_mr_idxs.data;
            unsigned *mri_ptr_end = mri_ptr + class_mr_idxs.used;

            do
            {
              // - MODULE LOAD ERROR -
              if (method_records[*mri_ptr].name_idx == method_name_idx)
              {
                error_code.push(ei_module_duplicate_class_method_name);
                error_code.push(module_names_positions[module_idx].ui_first);
                error_code.push(class_record_idx);
                error_code.push(method_name_idx);

                return false;
              }
            }
            while(++mri_ptr < mri_ptr_end);
          }

          // - creation of new method record -
          method_records.push_blank();
          unsigned method_record_idx = method_records.used - 1;
          method_record_s &method_record = method_records.last();

          // - setting of method parameters -
          method_record.name_idx = method_name_idx;
          method_record.modifiers = built_in_method.modifiers | c_modifier_built_in;
          method_record.parent_record = class_record_idx;

          // - store position of method name in code -
          name_pos_s &name_position = method_record.name_position;
          name_position.ui_first = c_idx_not_exist;
          name_position.ui_second = c_idx_not_exist;

          // - initialize method function pointer -
          method_record.bi_method_caller = built_in_method.method_caller;

          // - store method index to parent class -
          class_mr_idxs.push(method_record_idx);

        }
        while(++bim_idx < built_in_class.method_cnt);
      }

      if (built_in_class.variable_cnt != 0)
      {
        unsigned biv_idx = 0;
        do
        {
          built_in_variable_s &built_in_variable = built_in_class.variables[biv_idx];

          // - get index of variable name -
          unsigned variable_name_idx = variable_symbol_names.get_idx_char_ptr_insert(strlen(built_in_variable.name),built_in_variable.name);

          // - test variable name uniqueness in class -
          ui_array_s &class_vr_idxs = class_record.variable_record_idxs;

          if (class_vr_idxs.used != 0)
          {
            unsigned *vri_ptr = class_vr_idxs.data;
            unsigned *vri_ptr_end = vri_ptr + class_vr_idxs.used;

            // - test variable name uniqueness in class -
            do
            {
              // - MODULE LOAD ERROR -
              if (variable_records[*vri_ptr].name_idx == variable_name_idx)
              {
                error_code.push(ei_module_duplicate_class_element_name);
                error_code.push(module_names_positions[module_idx].ui_first);
                error_code.push(class_record_idx);
                error_code.push(variable_name_idx);

                return false;
              }
            }
            while(++vri_ptr < vri_ptr_end);
          }

          // - creation of new variable record -
          variable_records.push_blank();
          variable_record_s &variable_record = variable_records.last();
          variable_record.name_idx = variable_name_idx;
          variable_record.modifiers = built_in_variable.modifiers | c_modifier_built_in;
          variable_record.parent_record = class_record_idx;

          name_pos_s &name_position = variable_record.name_position;
          name_position.ui_first = c_idx_not_exist;
          name_position.ui_second = c_idx_not_exist;

          // - insert record index to class variable -
          class_vr_idxs.push(variable_records.used - 1);

        }
        while(++biv_idx < built_in_class.variable_cnt);
      }

    }
    while(++bic_idx < a_module_ptr->class_cnt);
  }

  // - MODULE LOAD ERROR -
  if (!a_module_ptr->initialize_caller(*this))
  {
    // - if error was not reported -
    if (error_code.used == 0)
    {
      error_code.push(ei_module_initialize_error);
      error_code.push(module_names_positions[module_idx].ui_first);
      error_code.push(module_idx);
    }

    return false;
  }

  return true;
}/*}}}*/

bool script_parser_s::load_module(const char *a_file_name)
{/*{{{*/
  dynlib_s dl;
  dl.init();

  // - open dynamic library -
  if (!dl.open(a_file_name,0))
  {
    //fprintf(stderr,"DL ERROR: %s\n",dl.get_error());

    dl.clear();
    return false;
  }

  built_in_module_s *module_ptr;

  // - get module symbol address -
  if (!dl.get_symbol_addr("module",(void **)&module_ptr))
  {
    dl.clear();
    return false;
  }

  // import classes from module
  if (!import_module(module_ptr))
  {
    dl.clear();
    return false;
  }

  bi_module_libs.push_blank();
  bi_module_libs.last().swap(dl);

  return true;
}/*}}}*/

void script_parser_s::initialize_parser(source_s &a_source,string_s &a_mods_path)
{/*{{{*/
  module_dirs.clear();

  // - insert default import directories -
  module_dirs.push_blanks(2);
  module_dirs[0].set(strlen("."),".");
  module_dirs[1].set(strlen("modules"),"modules");

  // - process import path -
  {
    string_array_s tmp_module_dirs;
    tmp_module_dirs.init();
    tmp_module_dirs.split(a_mods_path,1,":");

    if (tmp_module_dirs.used != 0)
    {
      string_s *s_ptr = tmp_module_dirs.data;
      string_s *s_ptr_end = s_ptr + tmp_module_dirs.used;
      do
      {
        // - if import directory is not empty -
        if (s_ptr->size > 1)
        {
          // - insert import directory to import directory list -
          module_dirs.push_blank();
          module_dirs.last().swap(*s_ptr);
        }
      }
      while(++s_ptr < s_ptr_end);
    }

    tmp_module_dirs.clear();
  }

  sources.clear();
  sources.push_blank();
  sources.last().swap(a_source);

  module_idx = 0;
  module_names.clear();
  module_names_positions.clear();

  bi_module_libs.clear();
  bi_module_pointers.clear();

  error_strings.clear();

  class_symbol_names.clear();
  method_symbol_names.clear();
  variable_symbol_names.clear();

  namespace_records.clear();
  class_records.clear();
  method_records.clear();
  variable_records.clear();

  namespace_name_idxs.clear();
  parent_namespace_idxs.clear();
  using_namespace_idxs.clear();

  const_chars.clear();
  const_ints.clear();
  const_floats.clear();
  const_strings.clear();
  const_delegates.clear();

  init_expressions.clear();
  method_flow_graphs.clear();

  im_descr.clear();

  static_begin_code.clear();
  static_run_time_code.clear();

  extending_idxs.clear();

  // - insertion of global namespace -
  {
    unsigned global_namespace_name_idx = class_symbol_names.get_idx_char_ptr_insert(6,"Global");

    namespace_records.push_blank();
    namespace_records.last().name_idx = global_namespace_name_idx;

    parent_namespace_idxs.push(0);
    using_namespace_idxs.push(0);
  }

  // - insertion of built in method symbols -
  {
    char **bi_m_ptr = (char **)c_built_in_method_symbol_names;
    char **bi_m_ptr_end = bi_m_ptr + c_built_in_method_cnt;
    unsigned *bi_m_idx_ptr = c_built_in_method_idxs;
    string_s tmp_str;

    do
    {
      tmp_str.data = *bi_m_ptr;
      tmp_str.size = strlen(*bi_m_ptr) + 1;

      *bi_m_idx_ptr = method_symbol_names.insert(tmp_str);
    }
    while(++bi_m_idx_ptr,++bi_m_ptr < bi_m_ptr_end);
  }

  // - load module containing base classes -
  module_names.push_blank();
  module_names.last().set(strlen("base"),"base");

  module_names_positions.push_blank();
  module_names_positions.last().set(SET_SRC_POS(0,0),SET_SRC_POS(0,0));

#if SYSTEM_TYPE_UNIX_CHROME_NACL == ENABLED
  cassert(load_module("/http/glibc/" CONFIG_NAME "/libbase_uclm_" NACL_ARCH DYNAMIC_LIB_EXTENSION));
#elif defined(ANDROID)
  cassert(load_module(ANDROID_APP_DIR "/lib/libbase_uclm" DYNAMIC_LIB_EXTENSION));
  //cassert(load_module("base_uclm" DYNAMIC_LIB_EXTENSION));
#else
  cassert(load_module("libbase_uclm" DYNAMIC_LIB_EXTENSION));
#endif

  module_idx++;
}/*}}}*/

unsigned script_parser_s::recognize_terminal(unsigned &input_idx) // NOLINT(google-readability-function-size,readability-function-size)
{/*{{{*/
  string_s &source_string = sources[source_idx].source_string;
  unsigned source_string_length = source_string.size - 1;

#define GET_NEXT_CHAR() \
  {\
    if (input_idx < source_string_length) {\
      in_char = (unsigned char)source_string[input_idx];\
    }\
    else {\
      in_char = '\0';\
    }\
  }

#define CLOSE_CHAR(RET_TERM_IDX) \
  {\
    if (in_char == '\0') {\
      return RET_TERM_IDX;\
    }\
\
    input_idx++;\
  }

   unsigned char in_char;

// - STATE 0 -
   GET_NEXT_CHAR();

   if (in_char == 0) {
      goto state_1_label;
   }
   if (in_char >= 8 && in_char < 14) {
      goto state_49_label;
   }
   if (in_char == 32) {
      goto state_49_label;
   }
   if (in_char == 33) {
      goto state_2_label;
   }
   if (in_char == 34) {
      goto state_3_label;
   }
   if (in_char == 35) {
      goto state_4_label;
   }
   if (in_char == 36) {
      goto state_5_label;
   }
   if (in_char == 37) {
      goto state_6_label;
   }
   if (in_char == 38) {
      goto state_7_label;
   }
   if (in_char == 39) {
      goto state_8_label;
   }
   if (in_char == 40) {
      goto state_9_label;
   }
   if (in_char == 41) {
      goto state_10_label;
   }
   if (in_char == 42) {
      goto state_11_label;
   }
   if (in_char == 43) {
      goto state_12_label;
   }
   if (in_char == 44) {
      goto state_13_label;
   }
   if (in_char == 45) {
      goto state_14_label;
   }
   if (in_char == 46) {
      goto state_15_label;
   }
   if (in_char == 47) {
      goto state_16_label;
   }
   if (in_char == 48) {
      goto state_17_label;
   }
   if (in_char >= 49 && in_char < 58) {
      goto state_18_label;
   }
   if (in_char == 58) {
      goto state_19_label;
   }
   if (in_char == 59) {
      goto state_20_label;
   }
   if (in_char == 60) {
      goto state_21_label;
   }
   if (in_char == 61) {
      goto state_22_label;
   }
   if (in_char == 62) {
      goto state_23_label;
   }
   if (in_char == 63) {
      goto state_24_label;
   }
   if (in_char == 64) {
      goto state_25_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 91) {
      goto state_26_label;
   }
   if (in_char == 93) {
      goto state_27_label;
   }
   if (in_char == 94) {
      goto state_28_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char == 97) {
      goto state_30_label;
   }
   if (in_char == 98) {
      goto state_31_label;
   }
   if (in_char == 99) {
      goto state_32_label;
   }
   if (in_char == 100) {
      goto state_33_label;
   }
   if (in_char == 101) {
      goto state_34_label;
   }
   if (in_char == 102) {
      goto state_35_label;
   }
   if (in_char >= 103 && in_char < 105) {
      goto state_29_label;
   }
   if (in_char == 105) {
      goto state_36_label;
   }
   if (in_char >= 106 && in_char < 110) {
      goto state_29_label;
   }
   if (in_char == 110) {
      goto state_37_label;
   }
   if (in_char == 111) {
      goto state_38_label;
   }
   if (in_char == 112) {
      goto state_39_label;
   }
   if (in_char == 113) {
      goto state_29_label;
   }
   if (in_char == 114) {
      goto state_40_label;
   }
   if (in_char == 115) {
      goto state_41_label;
   }
   if (in_char == 116) {
      goto state_42_label;
   }
   if (in_char == 117) {
      goto state_43_label;
   }
   if (in_char == 118) {
      goto state_29_label;
   }
   if (in_char == 119) {
      goto state_44_label;
   }
   if (in_char >= 120 && in_char < 123) {
      goto state_29_label;
   }
   if (in_char == 123) {
      goto state_45_label;
   }
   if (in_char == 124) {
      goto state_46_label;
   }
   if (in_char == 125) {
      goto state_47_label;
   }
   if (in_char == 126) {
      goto state_48_label;
   }
   return c_idx_not_exist;

// - STATE 1 -
state_1_label:
   CLOSE_CHAR(94);
   return 94;

// - STATE 2 -
state_2_label:
   CLOSE_CHAR(85);
   GET_NEXT_CHAR();

   if (in_char == 61) {
      goto state_51_label;
   }
   return 85;

// - STATE 3 -
state_3_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char < 34) {
      goto state_3_label;
   }
   if (in_char == 34) {
      goto state_52_label;
   }
   if (in_char < 92) {
      goto state_3_label;
   }
   if (in_char == 92) {
      goto state_53_label;
   }
   goto state_3_label;

// - STATE 4 -
state_4_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char < 10) {
      goto state_4_label;
   }
   if (in_char == 10) {
      goto state_54_label;
   }
   goto state_4_label;

// - STATE 5 -
state_5_label:
   CLOSE_CHAR(89);
   return 89;

// - STATE 6 -
state_6_label:
   CLOSE_CHAR(82);
   GET_NEXT_CHAR();

   if (in_char == 61) {
      goto state_55_label;
   }
   return 82;

// - STATE 7 -
state_7_label:
   CLOSE_CHAR(66);
   GET_NEXT_CHAR();

   if (in_char == 38) {
      goto state_56_label;
   }
   if (in_char == 61) {
      goto state_57_label;
   }
   return 66;

// - STATE 8 -
state_8_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char < 92) {
      goto state_59_label;
   }
   if (in_char == 92) {
      goto state_58_label;
   }
   goto state_59_label;

// - STATE 9 -
state_9_label:
   CLOSE_CHAR(30);
   return 30;

// - STATE 10 -
state_10_label:
   CLOSE_CHAR(31);
   return 31;

// - STATE 11 -
state_11_label:
   CLOSE_CHAR(80);
   GET_NEXT_CHAR();

   if (in_char == 61) {
      goto state_60_label;
   }
   return 80;

// - STATE 12 -
state_12_label:
   CLOSE_CHAR(77);
   GET_NEXT_CHAR();

   if (in_char == 43) {
      goto state_61_label;
   }
   if (in_char == 61) {
      goto state_62_label;
   }
   return 77;

// - STATE 13 -
state_13_label:
   CLOSE_CHAR(36);
   return 36;

// - STATE 14 -
state_14_label:
   CLOSE_CHAR(78);
   GET_NEXT_CHAR();

   if (in_char == 45) {
      goto state_63_label;
   }
   if (in_char == 61) {
      goto state_64_label;
   }
   if (in_char == 62) {
      goto state_65_label;
   }
   return 78;

// - STATE 15 -
state_15_label:
   CLOSE_CHAR(79);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_66_label;
   }
   return 79;

// - STATE 16 -
state_16_label:
   CLOSE_CHAR(81);
   GET_NEXT_CHAR();

   if (in_char == 42) {
      goto state_67_label;
   }
   if (in_char == 47) {
      goto state_68_label;
   }
   if (in_char == 61) {
      goto state_69_label;
   }
   return 81;

// - STATE 17 -
state_17_label:
   CLOSE_CHAR(5);
   GET_NEXT_CHAR();

   if (in_char == 46) {
      goto state_70_label;
   }
   if (in_char >= 48 && in_char < 56) {
      goto state_71_label;
   }
   if (in_char >= 56 && in_char < 58) {
      goto state_50_label;
   }
   if (in_char == 66) {
      goto state_72_label;
   }
   if (in_char == 69) {
      goto state_73_label;
   }
   if (in_char == 88) {
      goto state_74_label;
   }
   if (in_char == 98) {
      goto state_72_label;
   }
   if (in_char == 101) {
      goto state_73_label;
   }
   if (in_char == 120) {
      goto state_74_label;
   }
   return 5;

// - STATE 18 -
state_18_label:
   CLOSE_CHAR(6);
   GET_NEXT_CHAR();

   if (in_char == 46) {
      goto state_70_label;
   }
   if (in_char >= 48 && in_char < 58) {
      goto state_18_label;
   }
   if (in_char == 69) {
      goto state_73_label;
   }
   if (in_char == 101) {
      goto state_73_label;
   }
   return 6;

// - STATE 19 -
state_19_label:
   CLOSE_CHAR(87);
   return 87;

// - STATE 20 -
state_20_label:
   CLOSE_CHAR(37);
   return 37;

// - STATE 21 -
state_21_label:
   CLOSE_CHAR(72);
   GET_NEXT_CHAR();

   if (in_char == 45) {
      goto state_75_label;
   }
   if (in_char == 60) {
      goto state_76_label;
   }
   if (in_char == 61) {
      goto state_77_label;
   }
   return 72;

// - STATE 22 -
state_22_label:
   CLOSE_CHAR(53);
   GET_NEXT_CHAR();

   if (in_char == 61) {
      goto state_78_label;
   }
   if (in_char == 64) {
      goto state_79_label;
   }
   return 53;

// - STATE 23 -
state_23_label:
   CLOSE_CHAR(71);
   GET_NEXT_CHAR();

   if (in_char == 61) {
      goto state_80_label;
   }
   if (in_char == 62) {
      goto state_81_label;
   }
   return 71;

// - STATE 24 -
state_24_label:
   CLOSE_CHAR(86);
   return 86;

// - STATE 25 -
state_25_label:
   CLOSE_CHAR(26);
   return 26;

// - STATE 26 -
state_26_label:
   CLOSE_CHAR(34);
   return 34;

// - STATE 27 -
state_27_label:
   CLOSE_CHAR(35);
   return 35;

// - STATE 28 -
state_28_label:
   CLOSE_CHAR(68);
   GET_NEXT_CHAR();

   if (in_char == 61) {
      goto state_82_label;
   }
   return 68;

// - STATE 29 -
state_29_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 30 -
state_30_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char == 97) {
      goto state_29_label;
   }
   if (in_char == 98) {
      goto state_83_label;
   }
   if (in_char >= 99 && in_char < 110) {
      goto state_29_label;
   }
   if (in_char == 110) {
      goto state_84_label;
   }
   if (in_char >= 111 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 31 -
state_31_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 114) {
      goto state_29_label;
   }
   if (in_char == 114) {
      goto state_85_label;
   }
   if (in_char >= 115 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 32 -
state_32_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char == 97) {
      goto state_86_label;
   }
   if (in_char >= 98 && in_char < 108) {
      goto state_29_label;
   }
   if (in_char == 108) {
      goto state_87_label;
   }
   if (in_char >= 109 && in_char < 111) {
      goto state_29_label;
   }
   if (in_char == 111) {
      goto state_88_label;
   }
   if (in_char >= 112 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 33 -
state_33_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 101) {
      goto state_29_label;
   }
   if (in_char == 101) {
      goto state_89_label;
   }
   if (in_char >= 102 && in_char < 111) {
      goto state_29_label;
   }
   if (in_char == 111) {
      goto state_90_label;
   }
   if (in_char >= 112 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 34 -
state_34_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 108) {
      goto state_29_label;
   }
   if (in_char == 108) {
      goto state_91_label;
   }
   if (in_char >= 109 && in_char < 120) {
      goto state_29_label;
   }
   if (in_char == 120) {
      goto state_92_label;
   }
   if (in_char >= 121 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 35 -
state_35_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 105) {
      goto state_29_label;
   }
   if (in_char == 105) {
      goto state_93_label;
   }
   if (in_char >= 106 && in_char < 111) {
      goto state_29_label;
   }
   if (in_char == 111) {
      goto state_94_label;
   }
   if (in_char >= 112 && in_char < 114) {
      goto state_29_label;
   }
   if (in_char == 114) {
      goto state_95_label;
   }
   if (in_char >= 115 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 36 -
state_36_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 102) {
      goto state_29_label;
   }
   if (in_char == 102) {
      goto state_96_label;
   }
   if (in_char >= 103 && in_char < 109) {
      goto state_29_label;
   }
   if (in_char == 109) {
      goto state_97_label;
   }
   if (in_char == 110) {
      goto state_98_label;
   }
   if (in_char >= 111 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 37 -
state_37_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char == 97) {
      goto state_99_label;
   }
   if (in_char >= 98 && in_char < 101) {
      goto state_29_label;
   }
   if (in_char == 101) {
      goto state_100_label;
   }
   if (in_char >= 102 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 38 -
state_38_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 114) {
      goto state_29_label;
   }
   if (in_char == 114) {
      goto state_101_label;
   }
   if (in_char >= 115 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 39 -
state_39_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char == 97) {
      goto state_102_label;
   }
   if (in_char >= 98 && in_char < 114) {
      goto state_29_label;
   }
   if (in_char == 114) {
      goto state_103_label;
   }
   if (in_char >= 115 && in_char < 117) {
      goto state_29_label;
   }
   if (in_char == 117) {
      goto state_104_label;
   }
   if (in_char >= 118 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 40 -
state_40_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 101) {
      goto state_29_label;
   }
   if (in_char == 101) {
      goto state_105_label;
   }
   if (in_char >= 102 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 41 -
state_41_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 116) {
      goto state_29_label;
   }
   if (in_char == 116) {
      goto state_106_label;
   }
   if (in_char >= 117 && in_char < 119) {
      goto state_29_label;
   }
   if (in_char == 119) {
      goto state_107_label;
   }
   if (in_char >= 120 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 42 -
state_42_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 104) {
      goto state_29_label;
   }
   if (in_char == 104) {
      goto state_108_label;
   }
   if (in_char >= 105 && in_char < 114) {
      goto state_29_label;
   }
   if (in_char == 114) {
      goto state_109_label;
   }
   if (in_char >= 115 && in_char < 121) {
      goto state_29_label;
   }
   if (in_char == 121) {
      goto state_110_label;
   }
   if (in_char == 122) {
      goto state_29_label;
   }
   return 10;

// - STATE 43 -
state_43_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 115) {
      goto state_29_label;
   }
   if (in_char == 115) {
      goto state_111_label;
   }
   if (in_char >= 116 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 44 -
state_44_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 104) {
      goto state_29_label;
   }
   if (in_char == 104) {
      goto state_112_label;
   }
   if (in_char >= 105 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 45 -
state_45_label:
   CLOSE_CHAR(32);
   return 32;

// - STATE 46 -
state_46_label:
   CLOSE_CHAR(67);
   GET_NEXT_CHAR();

   if (in_char == 61) {
      goto state_113_label;
   }
   if (in_char == 124) {
      goto state_114_label;
   }
   return 67;

// - STATE 47 -
state_47_label:
   CLOSE_CHAR(33);
   return 33;

// - STATE 48 -
state_48_label:
   CLOSE_CHAR(88);
   return 88;

// - STATE 49 -
state_49_label:
   CLOSE_CHAR(90);
   GET_NEXT_CHAR();

   if (in_char >= 8 && in_char < 14) {
      goto state_49_label;
   }
   if (in_char == 32) {
      goto state_49_label;
   }
   return 90;

// - STATE 50 -
state_50_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 46) {
      goto state_70_label;
   }
   if (in_char >= 48 && in_char < 58) {
      goto state_50_label;
   }
   if (in_char == 69) {
      goto state_73_label;
   }
   if (in_char == 101) {
      goto state_73_label;
   }
   return c_idx_not_exist;

// - STATE 51 -
state_51_label:
   CLOSE_CHAR(70);
   return 70;

// - STATE 52 -
state_52_label:
   CLOSE_CHAR(9);
   return 9;

// - STATE 53 -
state_53_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 34) {
      goto state_3_label;
   }
   if (in_char == 39) {
      goto state_3_label;
   }
   if (in_char >= 48 && in_char < 56) {
      goto state_115_label;
   }
   if (in_char == 63) {
      goto state_3_label;
   }
   if (in_char == 92) {
      goto state_3_label;
   }
   if (in_char >= 97 && in_char < 99) {
      goto state_3_label;
   }
   if (in_char == 102) {
      goto state_3_label;
   }
   if (in_char == 110) {
      goto state_3_label;
   }
   if (in_char == 114) {
      goto state_3_label;
   }
   if (in_char == 116) {
      goto state_3_label;
   }
   if (in_char == 118) {
      goto state_3_label;
   }
   if (in_char == 120) {
      goto state_116_label;
   }
   return c_idx_not_exist;

// - STATE 54 -
state_54_label:
   CLOSE_CHAR(91);
   return 91;

// - STATE 55 -
state_55_label:
   CLOSE_CHAR(58);
   return 58;

// - STATE 56 -
state_56_label:
   CLOSE_CHAR(64);
   return 64;

// - STATE 57 -
state_57_label:
   CLOSE_CHAR(61);
   return 61;

// - STATE 58 -
state_58_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 34) {
      goto state_117_label;
   }
   if (in_char == 39) {
      goto state_118_label;
   }
   if (in_char >= 48 && in_char < 56) {
      goto state_119_label;
   }
   if (in_char == 63) {
      goto state_117_label;
   }
   if (in_char == 92) {
      goto state_117_label;
   }
   if (in_char >= 97 && in_char < 99) {
      goto state_117_label;
   }
   if (in_char == 102) {
      goto state_117_label;
   }
   if (in_char == 110) {
      goto state_117_label;
   }
   if (in_char == 114) {
      goto state_117_label;
   }
   if (in_char == 116) {
      goto state_117_label;
   }
   if (in_char == 118) {
      goto state_117_label;
   }
   if (in_char == 120) {
      goto state_120_label;
   }
   return c_idx_not_exist;

// - STATE 59 -
state_59_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 39) {
      goto state_121_label;
   }
   return c_idx_not_exist;

// - STATE 60 -
state_60_label:
   CLOSE_CHAR(56);
   return 56;

// - STATE 61 -
state_61_label:
   CLOSE_CHAR(83);
   return 83;

// - STATE 62 -
state_62_label:
   CLOSE_CHAR(54);
   return 54;

// - STATE 63 -
state_63_label:
   CLOSE_CHAR(84);
   return 84;

// - STATE 64 -
state_64_label:
   CLOSE_CHAR(55);
   return 55;

// - STATE 65 -
state_65_label:
   CLOSE_CHAR(29);
   return 29;

// - STATE 66 -
state_66_label:
   CLOSE_CHAR(8);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_66_label;
   }
   if (in_char == 69) {
      goto state_73_label;
   }
   if (in_char == 101) {
      goto state_73_label;
   }
   return 8;

// - STATE 67 -
state_67_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char < 42) {
      goto state_67_label;
   }
   if (in_char == 42) {
      goto state_122_label;
   }
   goto state_67_label;

// - STATE 68 -
state_68_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char < 10) {
      goto state_68_label;
   }
   if (in_char == 10) {
      goto state_123_label;
   }
   goto state_68_label;

// - STATE 69 -
state_69_label:
   CLOSE_CHAR(57);
   return 57;

// - STATE 70 -
state_70_label:
   CLOSE_CHAR(8);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_66_label;
   }
   if (in_char == 69) {
      goto state_73_label;
   }
   if (in_char == 101) {
      goto state_73_label;
   }
   return 8;

// - STATE 71 -
state_71_label:
   CLOSE_CHAR(5);
   GET_NEXT_CHAR();

   if (in_char == 46) {
      goto state_70_label;
   }
   if (in_char >= 48 && in_char < 56) {
      goto state_71_label;
   }
   if (in_char >= 56 && in_char < 58) {
      goto state_50_label;
   }
   if (in_char == 69) {
      goto state_73_label;
   }
   if (in_char == 101) {
      goto state_73_label;
   }
   return 5;

// - STATE 72 -
state_72_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 50) {
      goto state_124_label;
   }
   return c_idx_not_exist;

// - STATE 73 -
state_73_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 43) {
      goto state_125_label;
   }
   if (in_char == 45) {
      goto state_125_label;
   }
   if (in_char >= 48 && in_char < 58) {
      goto state_126_label;
   }
   return c_idx_not_exist;

// - STATE 74 -
state_74_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_127_label;
   }
   if (in_char >= 65 && in_char < 71) {
      goto state_127_label;
   }
   if (in_char >= 97 && in_char < 103) {
      goto state_127_label;
   }
   return c_idx_not_exist;

// - STATE 75 -
state_75_label:
   CLOSE_CHAR(28);
   return 28;

// - STATE 76 -
state_76_label:
   CLOSE_CHAR(76);
   GET_NEXT_CHAR();

   if (in_char == 61) {
      goto state_128_label;
   }
   return 76;

// - STATE 77 -
state_77_label:
   CLOSE_CHAR(74);
   return 74;

// - STATE 78 -
state_78_label:
   CLOSE_CHAR(69);
   return 69;

// - STATE 79 -
state_79_label:
   CLOSE_CHAR(27);
   return 27;

// - STATE 80 -
state_80_label:
   CLOSE_CHAR(73);
   return 73;

// - STATE 81 -
state_81_label:
   CLOSE_CHAR(75);
   GET_NEXT_CHAR();

   if (in_char == 61) {
      goto state_129_label;
   }
   return 75;

// - STATE 82 -
state_82_label:
   CLOSE_CHAR(63);
   return 63;

// - STATE 83 -
state_83_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 115) {
      goto state_29_label;
   }
   if (in_char == 115) {
      goto state_130_label;
   }
   if (in_char >= 116 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 84 -
state_84_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 100) {
      goto state_29_label;
   }
   if (in_char == 100) {
      goto state_131_label;
   }
   if (in_char >= 101 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 85 -
state_85_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 101) {
      goto state_29_label;
   }
   if (in_char == 101) {
      goto state_132_label;
   }
   if (in_char >= 102 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 86 -
state_86_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 115) {
      goto state_29_label;
   }
   if (in_char == 115) {
      goto state_133_label;
   }
   if (in_char == 116) {
      goto state_134_label;
   }
   if (in_char >= 117 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 87 -
state_87_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char == 97) {
      goto state_135_label;
   }
   if (in_char >= 98 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 88 -
state_88_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 110) {
      goto state_29_label;
   }
   if (in_char == 110) {
      goto state_136_label;
   }
   if (in_char >= 111 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 89 -
state_89_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 102) {
      goto state_29_label;
   }
   if (in_char == 102) {
      goto state_137_label;
   }
   if (in_char >= 103 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 90 -
state_90_label:
   CLOSE_CHAR(40);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 123) {
      goto state_29_label;
   }
   return 40;

// - STATE 91 -
state_91_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 115) {
      goto state_29_label;
   }
   if (in_char == 115) {
      goto state_138_label;
   }
   if (in_char >= 116 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 92 -
state_92_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 116) {
      goto state_29_label;
   }
   if (in_char == 116) {
      goto state_139_label;
   }
   if (in_char >= 117 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 93 -
state_93_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 110) {
      goto state_29_label;
   }
   if (in_char == 110) {
      goto state_140_label;
   }
   if (in_char >= 111 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 94 -
state_94_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 114) {
      goto state_29_label;
   }
   if (in_char == 114) {
      goto state_141_label;
   }
   if (in_char >= 115 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 95 -
state_95_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 101) {
      goto state_29_label;
   }
   if (in_char == 101) {
      goto state_142_label;
   }
   if (in_char >= 102 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 96 -
state_96_label:
   CLOSE_CHAR(38);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 123) {
      goto state_29_label;
   }
   return 38;

// - STATE 97 -
state_97_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 112) {
      goto state_29_label;
   }
   if (in_char == 112) {
      goto state_143_label;
   }
   if (in_char >= 113 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 98 -
state_98_label:
   CLOSE_CHAR(28);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 123) {
      goto state_29_label;
   }
   return 28;

// - STATE 99 -
state_99_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 109) {
      goto state_29_label;
   }
   if (in_char == 109) {
      goto state_144_label;
   }
   if (in_char >= 110 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 100 -
state_100_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 119) {
      goto state_29_label;
   }
   if (in_char == 119) {
      goto state_145_label;
   }
   if (in_char >= 120 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 101 -
state_101_label:
   CLOSE_CHAR(52);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 123) {
      goto state_29_label;
   }
   return 52;

// - STATE 102 -
state_102_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 114) {
      goto state_29_label;
   }
   if (in_char == 114) {
      goto state_146_label;
   }
   if (in_char >= 115 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 103 -
state_103_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 105) {
      goto state_29_label;
   }
   if (in_char == 105) {
      goto state_147_label;
   }
   if (in_char >= 106 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 104 -
state_104_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char == 97) {
      goto state_29_label;
   }
   if (in_char == 98) {
      goto state_148_label;
   }
   if (in_char >= 99 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 105 -
state_105_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 116) {
      goto state_29_label;
   }
   if (in_char == 116) {
      goto state_149_label;
   }
   if (in_char >= 117 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 106 -
state_106_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char == 97) {
      goto state_150_label;
   }
   if (in_char >= 98 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 107 -
state_107_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 105) {
      goto state_29_label;
   }
   if (in_char == 105) {
      goto state_151_label;
   }
   if (in_char >= 106 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 108 -
state_108_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 105) {
      goto state_29_label;
   }
   if (in_char == 105) {
      goto state_152_label;
   }
   if (in_char >= 106 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 109 -
state_109_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 121) {
      goto state_29_label;
   }
   if (in_char == 121) {
      goto state_153_label;
   }
   if (in_char == 122) {
      goto state_29_label;
   }
   return 10;

// - STATE 110 -
state_110_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 112) {
      goto state_29_label;
   }
   if (in_char == 112) {
      goto state_154_label;
   }
   if (in_char >= 113 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 111 -
state_111_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 105) {
      goto state_29_label;
   }
   if (in_char == 105) {
      goto state_155_label;
   }
   if (in_char >= 106 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 112 -
state_112_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 105) {
      goto state_29_label;
   }
   if (in_char == 105) {
      goto state_156_label;
   }
   if (in_char >= 106 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 113 -
state_113_label:
   CLOSE_CHAR(62);
   return 62;

// - STATE 114 -
state_114_label:
   CLOSE_CHAR(65);
   return 65;

// - STATE 115 -
state_115_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char < 34) {
      goto state_3_label;
   }
   if (in_char == 34) {
      goto state_52_label;
   }
   if (in_char < 48) {
      goto state_3_label;
   }
   if (in_char < 56) {
      goto state_157_label;
   }
   if (in_char < 92) {
      goto state_3_label;
   }
   if (in_char == 92) {
      goto state_53_label;
   }
   goto state_3_label;

// - STATE 116 -
state_116_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_158_label;
   }
   if (in_char >= 65 && in_char < 71) {
      goto state_158_label;
   }
   if (in_char >= 97 && in_char < 103) {
      goto state_158_label;
   }
   return c_idx_not_exist;

// - STATE 117 -
state_117_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 39) {
      goto state_159_label;
   }
   return c_idx_not_exist;

// - STATE 118 -
state_118_label:
   CLOSE_CHAR(0);
   GET_NEXT_CHAR();

   if (in_char == 39) {
      goto state_159_label;
   }
   return 0;

// - STATE 119 -
state_119_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 39) {
      goto state_160_label;
   }
   if (in_char >= 48 && in_char < 56) {
      goto state_161_label;
   }
   return c_idx_not_exist;

// - STATE 120 -
state_120_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_162_label;
   }
   if (in_char >= 65 && in_char < 71) {
      goto state_162_label;
   }
   if (in_char >= 97 && in_char < 103) {
      goto state_162_label;
   }
   return c_idx_not_exist;

// - STATE 121 -
state_121_label:
   CLOSE_CHAR(0);
   return 0;

// - STATE 122 -
state_122_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char < 47) {
      goto state_67_label;
   }
   if (in_char == 47) {
      goto state_163_label;
   }
   goto state_67_label;

// - STATE 123 -
state_123_label:
   CLOSE_CHAR(92);
   return 92;

// - STATE 124 -
state_124_label:
   CLOSE_CHAR(4);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 50) {
      goto state_124_label;
   }
   return 4;

// - STATE 125 -
state_125_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_126_label;
   }
   return c_idx_not_exist;

// - STATE 126 -
state_126_label:
   CLOSE_CHAR(8);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_126_label;
   }
   return 8;

// - STATE 127 -
state_127_label:
   CLOSE_CHAR(7);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_127_label;
   }
   if (in_char >= 65 && in_char < 71) {
      goto state_127_label;
   }
   if (in_char >= 97 && in_char < 103) {
      goto state_127_label;
   }
   return 7;

// - STATE 128 -
state_128_label:
   CLOSE_CHAR(59);
   return 59;

// - STATE 129 -
state_129_label:
   CLOSE_CHAR(60);
   return 60;

// - STATE 130 -
state_130_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 116) {
      goto state_29_label;
   }
   if (in_char == 116) {
      goto state_164_label;
   }
   if (in_char >= 117 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 131 -
state_131_label:
   CLOSE_CHAR(51);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 123) {
      goto state_29_label;
   }
   return 51;

// - STATE 132 -
state_132_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char == 97) {
      goto state_165_label;
   }
   if (in_char >= 98 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 133 -
state_133_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 101) {
      goto state_29_label;
   }
   if (in_char == 101) {
      goto state_166_label;
   }
   if (in_char >= 102 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 134 -
state_134_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 99) {
      goto state_29_label;
   }
   if (in_char == 99) {
      goto state_167_label;
   }
   if (in_char >= 100 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 135 -
state_135_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 115) {
      goto state_29_label;
   }
   if (in_char == 115) {
      goto state_168_label;
   }
   if (in_char >= 116 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 136 -
state_136_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 116) {
      goto state_29_label;
   }
   if (in_char == 116) {
      goto state_169_label;
   }
   if (in_char >= 117 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 137 -
state_137_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char == 97) {
      goto state_170_label;
   }
   if (in_char >= 98 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 138 -
state_138_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 101) {
      goto state_29_label;
   }
   if (in_char == 101) {
      goto state_171_label;
   }
   if (in_char >= 102 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 139 -
state_139_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 101) {
      goto state_29_label;
   }
   if (in_char == 101) {
      goto state_172_label;
   }
   if (in_char >= 102 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 140 -
state_140_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char == 97) {
      goto state_173_label;
   }
   if (in_char >= 98 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 141 -
state_141_label:
   CLOSE_CHAR(42);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 123) {
      goto state_29_label;
   }
   return 42;

// - STATE 142 -
state_142_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 101) {
      goto state_29_label;
   }
   if (in_char == 101) {
      goto state_174_label;
   }
   if (in_char >= 102 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 143 -
state_143_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 111) {
      goto state_29_label;
   }
   if (in_char == 111) {
      goto state_175_label;
   }
   if (in_char >= 112 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 144 -
state_144_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 101) {
      goto state_29_label;
   }
   if (in_char == 101) {
      goto state_176_label;
   }
   if (in_char >= 102 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 145 -
state_145_label:
   CLOSE_CHAR(22);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 123) {
      goto state_29_label;
   }
   return 22;

// - STATE 146 -
state_146_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char == 97) {
      goto state_177_label;
   }
   if (in_char >= 98 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 147 -
state_147_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 118) {
      goto state_29_label;
   }
   if (in_char == 118) {
      goto state_178_label;
   }
   if (in_char >= 119 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 148 -
state_148_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 108) {
      goto state_29_label;
   }
   if (in_char == 108) {
      goto state_179_label;
   }
   if (in_char >= 109 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 149 -
state_149_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 117) {
      goto state_29_label;
   }
   if (in_char == 117) {
      goto state_180_label;
   }
   if (in_char >= 118 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 150 -
state_150_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 116) {
      goto state_29_label;
   }
   if (in_char == 116) {
      goto state_181_label;
   }
   if (in_char >= 117 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 151 -
state_151_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 116) {
      goto state_29_label;
   }
   if (in_char == 116) {
      goto state_182_label;
   }
   if (in_char >= 117 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 152 -
state_152_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 115) {
      goto state_29_label;
   }
   if (in_char == 115) {
      goto state_183_label;
   }
   if (in_char >= 116 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 153 -
state_153_label:
   CLOSE_CHAR(49);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 123) {
      goto state_29_label;
   }
   return 49;

// - STATE 154 -
state_154_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 101) {
      goto state_29_label;
   }
   if (in_char == 101) {
      goto state_184_label;
   }
   if (in_char >= 102 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 155 -
state_155_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 110) {
      goto state_29_label;
   }
   if (in_char == 110) {
      goto state_185_label;
   }
   if (in_char >= 111 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 156 -
state_156_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 108) {
      goto state_29_label;
   }
   if (in_char == 108) {
      goto state_186_label;
   }
   if (in_char >= 109 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 157 -
state_157_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char < 34) {
      goto state_3_label;
   }
   if (in_char == 34) {
      goto state_52_label;
   }
   if (in_char < 92) {
      goto state_3_label;
   }
   if (in_char == 92) {
      goto state_53_label;
   }
   goto state_3_label;

// - STATE 158 -
state_158_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char < 34) {
      goto state_3_label;
   }
   if (in_char == 34) {
      goto state_52_label;
   }
   if (in_char < 92) {
      goto state_3_label;
   }
   if (in_char == 92) {
      goto state_53_label;
   }
   goto state_3_label;

// - STATE 159 -
state_159_label:
   CLOSE_CHAR(3);
   return 3;

// - STATE 160 -
state_160_label:
   CLOSE_CHAR(1);
   return 1;

// - STATE 161 -
state_161_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 39) {
      goto state_160_label;
   }
   if (in_char >= 48 && in_char < 56) {
      goto state_187_label;
   }
   return c_idx_not_exist;

// - STATE 162 -
state_162_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 39) {
      goto state_188_label;
   }
   if (in_char >= 48 && in_char < 58) {
      goto state_189_label;
   }
   if (in_char >= 65 && in_char < 71) {
      goto state_189_label;
   }
   if (in_char >= 97 && in_char < 103) {
      goto state_189_label;
   }
   return c_idx_not_exist;

// - STATE 163 -
state_163_label:
   CLOSE_CHAR(93);
   return 93;

// - STATE 164 -
state_164_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 114) {
      goto state_29_label;
   }
   if (in_char == 114) {
      goto state_190_label;
   }
   if (in_char >= 115 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 165 -
state_165_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 107) {
      goto state_29_label;
   }
   if (in_char == 107) {
      goto state_191_label;
   }
   if (in_char >= 108 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 166 -
state_166_label:
   CLOSE_CHAR(44);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 123) {
      goto state_29_label;
   }
   return 44;

// - STATE 167 -
state_167_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 104) {
      goto state_29_label;
   }
   if (in_char == 104) {
      goto state_192_label;
   }
   if (in_char >= 105 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 168 -
state_168_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 115) {
      goto state_29_label;
   }
   if (in_char == 115) {
      goto state_193_label;
   }
   if (in_char >= 116 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 169 -
state_169_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 105) {
      goto state_29_label;
   }
   if (in_char == 105) {
      goto state_194_label;
   }
   if (in_char >= 106 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 170 -
state_170_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 117) {
      goto state_29_label;
   }
   if (in_char == 117) {
      goto state_195_label;
   }
   if (in_char >= 118 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 171 -
state_171_label:
   CLOSE_CHAR(39);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 123) {
      goto state_29_label;
   }
   return 39;

// - STATE 172 -
state_172_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 110) {
      goto state_29_label;
   }
   if (in_char == 110) {
      goto state_196_label;
   }
   if (in_char >= 111 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 173 -
state_173_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 108) {
      goto state_29_label;
   }
   if (in_char == 108) {
      goto state_197_label;
   }
   if (in_char >= 109 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 174 -
state_174_label:
   CLOSE_CHAR(23);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 123) {
      goto state_29_label;
   }
   return 23;

// - STATE 175 -
state_175_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 114) {
      goto state_29_label;
   }
   if (in_char == 114) {
      goto state_198_label;
   }
   if (in_char >= 115 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 176 -
state_176_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 115) {
      goto state_29_label;
   }
   if (in_char == 115) {
      goto state_199_label;
   }
   if (in_char >= 116 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 177 -
state_177_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 108) {
      goto state_29_label;
   }
   if (in_char == 108) {
      goto state_200_label;
   }
   if (in_char >= 109 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 178 -
state_178_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char == 97) {
      goto state_201_label;
   }
   if (in_char >= 98 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 179 -
state_179_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 105) {
      goto state_29_label;
   }
   if (in_char == 105) {
      goto state_202_label;
   }
   if (in_char >= 106 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 180 -
state_180_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 114) {
      goto state_29_label;
   }
   if (in_char == 114) {
      goto state_203_label;
   }
   if (in_char >= 115 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 181 -
state_181_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 105) {
      goto state_29_label;
   }
   if (in_char == 105) {
      goto state_204_label;
   }
   if (in_char >= 106 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 182 -
state_182_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 99) {
      goto state_29_label;
   }
   if (in_char == 99) {
      goto state_205_label;
   }
   if (in_char >= 100 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 183 -
state_183_label:
   CLOSE_CHAR(24);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 123) {
      goto state_29_label;
   }
   return 24;

// - STATE 184 -
state_184_label:
   CLOSE_CHAR(25);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 123) {
      goto state_29_label;
   }
   return 25;

// - STATE 185 -
state_185_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 103) {
      goto state_29_label;
   }
   if (in_char == 103) {
      goto state_206_label;
   }
   if (in_char >= 104 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 186 -
state_186_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 101) {
      goto state_29_label;
   }
   if (in_char == 101) {
      goto state_207_label;
   }
   if (in_char >= 102 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 187 -
state_187_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 39) {
      goto state_160_label;
   }
   return c_idx_not_exist;

// - STATE 188 -
state_188_label:
   CLOSE_CHAR(2);
   return 2;

// - STATE 189 -
state_189_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 39) {
      goto state_188_label;
   }
   return c_idx_not_exist;

// - STATE 190 -
state_190_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char == 97) {
      goto state_208_label;
   }
   if (in_char >= 98 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 191 -
state_191_label:
   CLOSE_CHAR(46);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 123) {
      goto state_29_label;
   }
   return 46;

// - STATE 192 -
state_192_label:
   CLOSE_CHAR(50);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 123) {
      goto state_29_label;
   }
   return 50;

// - STATE 193 -
state_193_label:
   CLOSE_CHAR(14);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 123) {
      goto state_29_label;
   }
   return 14;

// - STATE 194 -
state_194_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 110) {
      goto state_29_label;
   }
   if (in_char == 110) {
      goto state_209_label;
   }
   if (in_char >= 111 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 195 -
state_195_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 108) {
      goto state_29_label;
   }
   if (in_char == 108) {
      goto state_210_label;
   }
   if (in_char >= 109 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 196 -
state_196_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 100) {
      goto state_29_label;
   }
   if (in_char == 100) {
      goto state_211_label;
   }
   if (in_char >= 101 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 197 -
state_197_label:
   CLOSE_CHAR(20);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 123) {
      goto state_29_label;
   }
   return 20;

// - STATE 198 -
state_198_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 116) {
      goto state_29_label;
   }
   if (in_char == 116) {
      goto state_212_label;
   }
   if (in_char >= 117 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 199 -
state_199_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 112) {
      goto state_29_label;
   }
   if (in_char == 112) {
      goto state_213_label;
   }
   if (in_char >= 113 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 200 -
state_200_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 108) {
      goto state_29_label;
   }
   if (in_char == 108) {
      goto state_214_label;
   }
   if (in_char >= 109 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 201 -
state_201_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 116) {
      goto state_29_label;
   }
   if (in_char == 116) {
      goto state_215_label;
   }
   if (in_char >= 117 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 202 -
state_202_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 99) {
      goto state_29_label;
   }
   if (in_char == 99) {
      goto state_216_label;
   }
   if (in_char >= 100 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 203 -
state_203_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 110) {
      goto state_29_label;
   }
   if (in_char == 110) {
      goto state_217_label;
   }
   if (in_char >= 111 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 204 -
state_204_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 99) {
      goto state_29_label;
   }
   if (in_char == 99) {
      goto state_218_label;
   }
   if (in_char >= 100 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 205 -
state_205_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 104) {
      goto state_29_label;
   }
   if (in_char == 104) {
      goto state_219_label;
   }
   if (in_char >= 105 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 206 -
state_206_label:
   CLOSE_CHAR(13);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 123) {
      goto state_29_label;
   }
   return 13;

// - STATE 207 -
state_207_label:
   CLOSE_CHAR(41);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 123) {
      goto state_29_label;
   }
   return 41;

// - STATE 208 -
state_208_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 99) {
      goto state_29_label;
   }
   if (in_char == 99) {
      goto state_220_label;
   }
   if (in_char >= 100 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 209 -
state_209_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 117) {
      goto state_29_label;
   }
   if (in_char == 117) {
      goto state_221_label;
   }
   if (in_char >= 118 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 210 -
state_210_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 116) {
      goto state_29_label;
   }
   if (in_char == 116) {
      goto state_222_label;
   }
   if (in_char >= 117 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 211 -
state_211_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 115) {
      goto state_29_label;
   }
   if (in_char == 115) {
      goto state_223_label;
   }
   if (in_char >= 116 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 212 -
state_212_label:
   CLOSE_CHAR(11);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 123) {
      goto state_29_label;
   }
   return 11;

// - STATE 213 -
state_213_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char == 97) {
      goto state_224_label;
   }
   if (in_char >= 98 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 214 -
state_214_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 101) {
      goto state_29_label;
   }
   if (in_char == 101) {
      goto state_225_label;
   }
   if (in_char >= 102 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 215 -
state_215_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 101) {
      goto state_29_label;
   }
   if (in_char == 101) {
      goto state_226_label;
   }
   if (in_char >= 102 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 216 -
state_216_label:
   CLOSE_CHAR(16);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 123) {
      goto state_29_label;
   }
   return 16;

// - STATE 217 -
state_217_label:
   CLOSE_CHAR(48);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 123) {
      goto state_29_label;
   }
   return 48;

// - STATE 218 -
state_218_label:
   CLOSE_CHAR(18);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 123) {
      goto state_29_label;
   }
   return 18;

// - STATE 219 -
state_219_label:
   CLOSE_CHAR(43);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 123) {
      goto state_29_label;
   }
   return 43;

// - STATE 220 -
state_220_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 116) {
      goto state_29_label;
   }
   if (in_char == 116) {
      goto state_227_label;
   }
   if (in_char >= 117 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 221 -
state_221_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 101) {
      goto state_29_label;
   }
   if (in_char == 101) {
      goto state_228_label;
   }
   if (in_char >= 102 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 222 -
state_222_label:
   CLOSE_CHAR(45);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 123) {
      goto state_29_label;
   }
   return 45;

// - STATE 223 -
state_223_label:
   CLOSE_CHAR(15);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 123) {
      goto state_29_label;
   }
   return 15;

// - STATE 224 -
state_224_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 99) {
      goto state_29_label;
   }
   if (in_char == 99) {
      goto state_229_label;
   }
   if (in_char >= 100 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 225 -
state_225_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 108) {
      goto state_29_label;
   }
   if (in_char == 108) {
      goto state_230_label;
   }
   if (in_char >= 109 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 226 -
state_226_label:
   CLOSE_CHAR(17);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 123) {
      goto state_29_label;
   }
   return 17;

// - STATE 227 -
state_227_label:
   CLOSE_CHAR(19);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 123) {
      goto state_29_label;
   }
   return 19;

// - STATE 228 -
state_228_label:
   CLOSE_CHAR(47);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 123) {
      goto state_29_label;
   }
   return 47;

// - STATE 229 -
state_229_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 101) {
      goto state_29_label;
   }
   if (in_char == 101) {
      goto state_231_label;
   }
   if (in_char >= 102 && in_char < 123) {
      goto state_29_label;
   }
   return 10;

// - STATE 230 -
state_230_label:
   CLOSE_CHAR(21);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 123) {
      goto state_29_label;
   }
   return 21;

// - STATE 231 -
state_231_label:
   CLOSE_CHAR(12);
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_29_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_29_label;
   }
   if (in_char == 95) {
      goto state_29_label;
   }
   if (in_char >= 97 && in_char < 123) {
      goto state_29_label;
   }
   return 12;

}/*}}}*/

void script_parser_s::parse_script(unsigned a_source_idx)
{/*{{{*/
  debug_assert(a_source_idx < sources.used);

  source_idx = a_source_idx;
  old_input_idx = 0;
  modifiers = 0;

  parent_class_idxs.clear();
  parent_method_idxs.clear();

  try_fg_map_idxs.clear();

  tmp_name_pos_array.clear();
  member_cnt.clear();
  error_code.clear();

  switch_descrs.clear();
  switch_expression_descrs.clear();

  code_descrs.clear();
  code_descrs.push_blank();

  lalr_stack.clear();
  lalr_stack.push(0);

  unsigned input_idx = 0;
  unsigned ret_term = c_idx_not_exist;

  // - decipher cryptic source code -
  {
    string_s &source = sources[source_idx].source_string;

    cipher_s cipher;
    cipher.init();

    // - if source code is cryptical -
    if (cipher.is_cipher(source.size - 1,source.data))
    {
      cipher.create(c_ck_length,(char *)c_ck_value);

      // - decipher cryptical source code -
      cipher.process((source.size - 1) - c_cm_length,source.data + c_cm_length);
      input_idx = c_cm_length;
    }

    cipher.clear();
  }

  do
  {
    // - retrieve next terminal symbol -
    while (ret_term == c_idx_not_exist)
    {
      old_input_idx = input_idx;

      ret_term = recognize_terminal(input_idx);
      debug_message_5(fprintf(stderr,"script_parser: recognized terminal: %u\n",ret_term));

      // - PARSE ERROR unrecognized terminal -
      if (ret_term == c_idx_not_exist)
      {
        error_code.push(ei_unrecognizable_terminal);
        error_code.push(SET_SRC_POS(source_idx,old_input_idx));

        return;
      }

      // - skipping of _SKIP_ terminals -
      if (ret_term >= 90 && ret_term <= 93)
      {
        ret_term = c_idx_not_exist;
      }
    }

    // - retrieve action from table of actions -
    unsigned parse_action = lalr_table[(lalr_stack.last().lalr_state*c_terminal_plus_nonterminal_cnt) + ret_term];

    // - PARSE ERROR wrong syntax -
    if (parse_action == c_idx_not_exist)
    {
      error_code.push(ei_wrong_program_syntax);
      error_code.push(SET_SRC_POS(source_idx,old_input_idx));

      return;
    }

    // - action SHIFT -
    if (parse_action < c_lalr_table_reduce_base)
    {
      if (ret_term == 94)
      {
        break;
      }

      // - insertion of state, and terminal position in source string -
      lalr_stack.push(parse_action,old_input_idx,input_idx);
      ret_term = c_idx_not_exist;
    }

    // - action REDUCE-
    else
    {
      parse_action -= c_lalr_table_reduce_base;

      // - call assigned function to reduction -
      if (script_pa_callers[parse_action] != pa_null)
      {
        if (!script_pa_callers[parse_action](sources[source_idx].source_string,*this))
        {
          return;
        }
      }

      // - remove rule body from lalr_stack -
      lalr_stack.used -= rule_body_lengths[parse_action];

      // - insert new automat state to stack -
      unsigned goto_val = lalr_table[(lalr_stack.last().lalr_state*c_terminal_plus_nonterminal_cnt) + rule_head_idxs[parse_action]];
      lalr_stack.push(goto_val);
    }

  }
  while(true);
}/*}}}*/

void script_parser_s::process_modules()
{/*{{{*/
  string_s file_name;
  file_name.init();

  if (module_idx < module_names.used)
  {
    do
    {
      // - format module name -
#if SYSTEM_TYPE_UNIX_CHROME_NACL == ENABLED
      file_name.setf("/http/glibc/" CONFIG_NAME "/lib%s_uclm_" NACL_ARCH DYNAMIC_LIB_EXTENSION,module_names[module_idx].data);
#elif defined(ANDROID)
      file_name.setf(ANDROID_APP_DIR "/lib/lib%s_uclm" DYNAMIC_LIB_EXTENSION,module_names[module_idx].data);
      //file_name.setf("%s_uclm" DYNAMIC_LIB_EXTENSION,module_names[module_idx].data);
#else
      file_name.setf("lib%s_uclm" DYNAMIC_LIB_EXTENSION,module_names[module_idx].data);
#endif

      // - load build in module -
      if (load_module(file_name.data))
      {
        debug_message_2(fprintf(stderr,"script_parser: imported module \"%s\" as library \"%s\" \n",module_names[module_idx].data,file_name.data););
        continue;
      }

      // - if some errors has been occurred -
      if (error_code.used != 0)
      {
        file_name.clear();
        return;
      }

      // - process all module search directories -
      if (module_dirs.used != 0)
      {
        string_s *md_ptr = module_dirs.data;
        string_s *md_ptr_end = md_ptr + module_dirs.used;
        do
        {
          file_name.setf("%s/%s.ucl",md_ptr->data,module_names[module_idx].data);

          string_s source_string;
          source_string.init();

          // - read source string from file -
          if (source_string.load_text_file(file_name.data))
          {
            // - insert module source to script parser -
            sources.push_blank();
            source_s &source = sources.last();

            // - set source file name -
            source.file_name.swap(file_name);
            file_name.clear();

            // - set source source string -
            source.source_string.swap(source_string);
            source_string.clear();

            // - parse module source string -
            parse_script(sources.used - 1);

            // - test if errors were occurred while parsing module source string -
            if (error_code.used != 0)
            {
              return;
            }

            debug_message_2(fprintf(stderr,"script_parser: imported module \"%s\" as source file \"%s\"\n",module_names[module_idx].data,source.file_name.data););

            break;
          }

          source_string.clear();
        }
        while(++md_ptr < md_ptr_end);

        // - if module file was found -
        if (md_ptr < md_ptr_end)
        {
          continue;
        }
      }

      // - MODULE IMPORT ERROR -
      error_code.push(ei_cannot_find_module);
      error_code.push(module_names_positions[module_idx].ui_first);
      error_code.push(module_idx);

      file_name.clear();
      return;

    }
    while(++module_idx < module_names.used);
  }

  file_name.clear();
}/*}}}*/

void script_parser_s::extended_classes_search()
{/*{{{*/

  if (extending_idxs.used != 0)
  {
    unsigned *ep_ptr = extending_idxs.data;
    unsigned *ep_ptr_end = ep_ptr + extending_idxs.used;

    do
    {
      class_record_s &extending_class = class_records[*ep_ptr];

      // - set class using namespaces -
      using_namespace_idxs.swap(extending_class.using_namespace_idxs);

      ui_array_s &extend_array = extending_class.extend_array;
      unsigned ext_class_idx;

      // - retrieve index of extended class record -
      {
        unsigned name_cnt = extend_array.used >> 1;

        // - class name with preceding namespaces -
        if (name_cnt > 1)
        {
          // - retrieve namespace record index -
          unsigned namespace_ri = resolve_namespace_idx_by_name_idx(extend_array[0]);

          // - SEMANTIC ERROR -
          if (namespace_ri == c_idx_not_exist)
          {
            // - reset class using namespaces -
            extending_class.using_namespace_idxs.swap(using_namespace_idxs);

            error_code.push(ei_namespace_name_cannot_be_resolved);
            error_code.push(extend_array[1]);
            error_code.push(extend_array[0]);

            extending_class.extend_class_idx = c_idx_not_exist;
            return;
          }

          unsigned *name_ptr = extend_array.data + 2;

          if (name_cnt > 2)
          {
            unsigned *name_ptr_end = name_ptr + extend_array.used - 4;
            do
            {
              // - retrieve next namespace record index -
              namespace_ri = get_parent_namespace_namespace_idx_by_name_idx(*name_ptr,namespace_ri);

              // - SEMANTIC ERROR -
              if (namespace_ri == c_idx_not_exist)
              {
                // - reset class using namespaces -
                extending_class.using_namespace_idxs.swap(using_namespace_idxs);

                error_code.push(ei_namespace_name_cannot_be_resolved);
                error_code.push(name_ptr[1]);
                error_code.push(name_ptr[0]);

                extending_class.extend_class_idx = c_idx_not_exist;
                return;
              }

            } while((name_ptr += 2) < name_ptr_end);
          }

          // - retrieve class record index -
          ext_class_idx = get_parent_namespace_class_idx_by_name_idx(*name_ptr,namespace_ri);
        }

        // - only class name -
        else
        {
          // - retrieve class record index -
          ext_class_idx = resolve_class_idx_by_name_idx(extend_array[0],extending_class.parent_record);
        }
      }

      // - reset class using namespaces -
      extending_class.using_namespace_idxs.swap(using_namespace_idxs);

      // - SEMANTIC ERROR -
      if (ext_class_idx == c_idx_not_exist)
      {
        error_code.push(ei_cannot_resolve_extended_class);
        error_code.push(extending_class.name_position.ui_first);
        error_code.push(extend_array[extend_array.used - 2]);

        extending_class.extend_class_idx = c_idx_not_exist;
        return;
      }

      // - SEMANTIC ERROR -
      if (ext_class_idx == *ep_ptr)
      {
        error_code.push(ei_class_cannot_extend_itself);
        error_code.push(extending_class.name_position.ui_first);

        extending_class.extend_class_idx = c_idx_not_exist;
        return;
      }

      // - SEMANTIC ERROR extended class is defined as final -
      if (class_records[ext_class_idx].modifiers & c_modifier_final)
      {
        error_code.push(ei_cannot_extend_final_class);
        error_code.push(extending_class.name_position.ui_first);
        error_code.push(extend_array[extend_array.used - 2]);

        extending_class.extend_class_idx = c_idx_not_exist;
        return;
      }

      debug_message_5(fprintf(stderr,"script_parser: class %s extends class search %s -> %u\n",class_symbol_names[extending_class.name_idx].data,class_symbol_names[extending_class.extend_class_idx].data,ext_class_idx));

      // - release extend array values -
      extend_array.used = 0;

      // - insertion extended class index to record of extending class -
      extending_class.extend_class_idx = ext_class_idx;
    }
    while(++ep_ptr < ep_ptr_end);
  }
}/*}}}*/

void script_parser_s::element_search()
{/*{{{*/

  // - acquire count of program constants -
  unsigned constant_cnt =
    const_chars.used + const_ints.used + const_floats.used +
    const_strings.used + const_delegates.used + class_records.used;

  // - counters of static constant elements and static elements -
  static_const_element_cnt = 0;
  static_element_cnt = 0;

  // - method symbol names power -
  method_sn_pow = 0;
  while ((1U << method_sn_pow) < method_symbol_names.used)
  {
    ++method_sn_pow;
  }

  // - if there are any class records -
  if (class_records.used != 0)
  {
    // - method symbol names maps -
    unsigned method_sn_map_size = class_records.used << method_sn_pow;

    method_snri_map.used = 0;
    method_snri_map.copy_resize(method_sn_map_size);
    method_snri_map.used = method_sn_map_size;
    memset(method_snri_map.data,(int)c_idx_not_exist,method_snri_map.used*sizeof(unsigned));

    method_snbi_map.used = 0;
    method_snbi_map.copy_resize(method_sn_map_size);
    method_snbi_map.used = method_sn_map_size;
    memset(method_snbi_map.data,0,method_snbi_map.used*sizeof(pointer));

    // - cycle through all classes, initialize vn_ri_ep_map functions -
    {
      unsigned cl_idx = 0;
      do
      {
        class_record_s &class_record = class_records[cl_idx];

        debug_message_6(fprintf(stderr,"script_parser: initialize vn_ri_ep_map of class: %s\n",class_symbol_names[class_record.name_idx].data));

        // - clear function mapping variable names to class variables -
        ri_ep_array_s &vn_ri_ep_map = class_record.vn_ri_ep_map;
        vn_ri_ep_map.used = 0;
        vn_ri_ep_map.copy_resize(variable_symbol_names.used);
        vn_ri_ep_map.used = variable_symbol_names.used;

        debug_assert(vn_ri_ep_map.data != nullptr);
        memset(vn_ri_ep_map.data,(int)c_idx_not_exist,vn_ri_ep_map.used*sizeof(ri_ep_s));

      }
      while(++cl_idx < class_records.used);
    }

    unsigned class_idx = 0;

    // - cycle through all class records -
    do
    {
      class_record_s &class_record = class_records[class_idx];

      debug_message_6(fprintf(stderr,"script_parser: search elements of class: %s\n",class_symbol_names[class_record.name_idx].data));

      unsigned *snri_arr = method_snri_map.data + (class_idx << method_sn_pow);
      pointer *mnbi_arr = method_snbi_map.data + (class_idx << method_sn_pow);
      ri_ep_array_s &vn_ri_ep_map = class_record.vn_ri_ep_map;

      unsigned extended_class_idx = class_idx;
      unsigned class_element_cnt = 0;

      // - cycle through extended classes -
      do
      {
        class_record_s &extended_class = class_records[extended_class_idx];

        debug_message_6(fprintf(stderr,"script_parser: class %s extend class %s\n",class_symbol_names[class_record.name_idx].data,class_symbol_names[extended_class.name_idx].data));

        ui_array_s &method_record_idxs = extended_class.method_record_idxs;
        ui_array_s &variable_record_idxs = extended_class.variable_record_idxs;

        // - insertion of extended class record index to list of extended classes -
        class_record.extend_array.push(extended_class_idx);

        // - if extended class contain some methods, and class is not defined as abstract -
        if (method_record_idxs.used != 0 && !(class_record.modifiers & c_modifier_abstract))
        {
          unsigned *mri_ptr = method_record_idxs.data;
          unsigned *mri_ptr_end = mri_ptr + method_record_idxs.used;

          // - cycle through class methods -
          do
          {
            method_record_s &method_record = method_records[*mri_ptr];
            debug_message_6(fprintf(stderr,"script_parser: class %s extend class %s, method: %s\n",class_symbol_names[class_record.name_idx].data,class_symbol_names[extended_class.name_idx].data,method_symbol_names[method_record.name_idx].data));

            if (method_record.modifiers & c_modifier_abstract)
            {
              // - SEMANTIC ERROR if method is defined as abstract assure that it was defined in some extending class -
              if (snri_arr[method_record.name_idx] == c_idx_not_exist)
              {
                error_code.push(ei_must_implement_inherited_abstract_method);
                error_code.push(class_record.name_position.ui_first);
                error_code.push(class_idx);
                error_code.push(*mri_ptr);
              }
            }
            else
            {
              // - if method has not been defined so far, save index of its record to mapping function -
              unsigned &method_record_idx = snri_arr[method_record.name_idx];

              if (method_record.modifiers & c_modifier_final)
              {
                // - SEMANTIC ERROR -
                if (method_record_idx != c_idx_not_exist)
                {
                  error_code.push(ei_cannot_override_final_method);
                  error_code.push(method_records[method_record_idx].name_position.ui_first);
                  error_code.push(method_record_idx);
                  error_code.push(*mri_ptr);

                  return;
                }
              }

              if (method_record_idx == c_idx_not_exist)
              {
                method_record_idx = *mri_ptr;

                if (method_record.modifiers & c_modifier_built_in)
                {
                  // - set method name built in caller -
                  mnbi_arr[method_record.name_idx] = (pointer)method_record.bi_method_caller;
                }
              }
            }

          }
          while(++mri_ptr < mri_ptr_end);
        }

        // - if class contain some variables -
        if (variable_record_idxs.used != 0)
        {
          unsigned *vri_ptr = variable_record_idxs.data;
          unsigned *vri_ptr_end = vri_ptr + variable_record_idxs.used;

          // - set mapping array at index of its name to index of its record, and its position in class -
          do
          {
            variable_record_s &variable_record = variable_records[*vri_ptr];
            debug_message_6(fprintf(stderr,"script_parser: class %s extend class %s, variable: %s\n",class_symbol_names[class_record.name_idx].data,class_symbol_names[extended_class.name_idx].data,variable_symbol_names[variable_record.name_idx].data));

            ri_ep_s &ri_ep = vn_ri_ep_map[variable_record.name_idx];

            if (ri_ep.record_idx == c_idx_not_exist)
            {
              ri_ep.record_idx = *vri_ptr;

              if (variable_record.modifiers & c_modifier_static)
              {
                if (variable_record.modifiers & c_modifier_static_const)
                {
                  // - if variable is static constant save to element position index of constant -
                  ri_ep.element_position = constant_cnt + static_const_element_cnt++;
                }
                else
                {
                  // - retrieve reference to static variable base class variable name, record index, element position map -
                  ri_ep_s &ec_ri_ep = extended_class.vn_ri_ep_map[variable_record.name_idx];

                  if (ec_ri_ep.element_position == c_idx_not_exist)
                  {
                    ec_ri_ep.record_idx = *vri_ptr;
                    ec_ri_ep.element_position = static_element_cnt++;
                  }

                  ri_ep.element_position = ec_ri_ep.element_position;
                }
              }
              else
              {
                // - if variable is not static save to its element next position in class -
                ri_ep.element_position = class_element_cnt++;
              }
            }

          }
          while(++vri_ptr < vri_ptr_end);
        }

        extended_class_idx = extended_class.extend_class_idx;
      }
      while(extended_class_idx != c_idx_not_exist);

      // - set class variable cnt -
      class_record.element_cnt = class_element_cnt;

    }
    while(++class_idx < class_records.used);
  }
}/*}}}*/

bool script_parser_s::generate_expression_intermediate_code(uli_array_s &begin_code,uli_array_s &code,expression_s &exp)
{/*{{{*/
  debug_assert(exp.start_node_idx != c_idx_not_exist && exp.nodes.used != 0);

  // - initialization of temporary stack of expression nodes -
  im_descr.exp_node_stack.used = 0;
  im_descr.exp_node_stack.push(exp.start_node_idx);

  // - setting of array for storing of processed nodes -
  if (im_descr.done_exp_nodes.used <= exp.nodes.used)
  {
    im_descr.done_exp_nodes.used = 0;
    im_descr.done_exp_nodes.copy_resize(exp.nodes.used);
    im_descr.done_exp_nodes.used = exp.nodes.used;
  }

  memset(im_descr.done_exp_nodes.data,0xffff,exp.nodes.used*sizeof(unsigned));

  // - clear array of expression operands -
  im_descr.operands.used = 0;
  im_descr.operand_stack.used = 0;

  do
  {
    // - launching of action which generates intermediate code  -
    if (!(script_im_callers[exp.nodes[im_descr.exp_node_stack.last()]](exp,begin_code,code,*this)))
    {
      return false;
    }

  }
  while(im_descr.exp_node_stack.used > 0);

  return true;
}/*}}}*/

bool script_parser_s::generate_method_intermediate_code()
{/*{{{*/

  // - retrieve method record and flow graph -
  method_record_s &method_record = method_records[im_descr.method_idx];
  exp_flow_graph_s &fg = method_flow_graphs[method_record.flow_graph_idx];

  // - reset free stack indexes -
  im_descr.free_stack_idxs.used = 0;

  // - clear array of identifier operands, and clear of variable name mapping -
  im_descr.found_operands.used = 0;
  memset(im_descr.var_name_fo_map.data,(int)c_idx_not_exist,im_descr.var_name_fo_map.used*sizeof(unsigned));
  memset(im_descr.const_idx_fo_map.data,(int)c_idx_not_exist,im_descr.const_idx_fo_map.used*sizeof(unsigned));
  if (im_descr.static_vi_fo_map.used != 0) {
    memset(im_descr.static_vi_fo_map.data,(int)c_idx_not_exist,im_descr.static_vi_fo_map.used*sizeof(unsigned));
  }

  unsigned me_idx = 0;
  unsigned *fgn_ptr = fg.nodes.data;
  unsigned *fgn_ptr_end = fgn_ptr + fg.nodes.used;

  // - cycle through method expressions -
  do
  {
#define GENERATE_INTERMEDIATE_CODE_PROCESS_EXPRESSION(CODE) \
{/*{{{*/\
\
  /* - attach expression code to flow graph node - */\
  fgn_ptr[c_fg_expression_idx] = method_record.run_time_code.used;\
\
  im_descr.exp_idx = me_idx;\
  if (!generate_expression_intermediate_code(method_record.begin_code,method_record.run_time_code,fg.expressions[me_idx]))\
  {\
    return false;\
  }\
\
  /* - increase method expression index - */\
  me_idx++;\
\
  /* - pointer to last expression operand - */\
  op_ptr = im_descr.operands.data + im_descr.operand_stack.pop();\
\
  CODE;\
\
  /* - if last operand is temporary, insert its index to free position list - */\
  if (*op_ptr & c_op_modifier_tmp)\
  {\
    im_descr.free_stack_idxs.push(op_ptr[1]);\
  }\
}/*}}}*/

    unsigned *op_ptr;

    // - generation of last instruction of expression base on flow graph node type -
    switch (*fgn_ptr)
    {
    case c_fg_type_expression:
      GENERATE_INTERMEDIATE_CODE_PROCESS_EXPRESSION(
        method_record.run_time_code.push(i_expression_end);
        fgn_ptr += c_fg_expression_size;
      );
      break;
    case c_fg_type_condition:
      GENERATE_INTERMEDIATE_CODE_PROCESS_EXPRESSION(
        method_record.run_time_code.push(i_return);
        method_record.run_time_code.push(op_ptr[1]);

        // - ERROR -
        if (!(*op_ptr & c_op_modifier_object))
        {
          error_code.push(ei_expected_object_as_operand);
          error_code.push(fgn_ptr[c_fg_condition_source_pos]);
        }

        fgn_ptr += c_fg_condition_size;
      );
      break;
    case c_fg_type_return_expression:
      GENERATE_INTERMEDIATE_CODE_PROCESS_EXPRESSION(
        method_record.run_time_code.push(i_return);
        method_record.run_time_code.push(op_ptr[1]);

        // - ERROR -
        if (!(*op_ptr & c_op_modifier_object))
        {
          error_code.push(ei_expected_object_as_operand);
          error_code.push(fgn_ptr[c_fg_return_expression_source_pos]);
        }

        fgn_ptr += c_fg_return_expression_size;
      );
      break;
    case c_fg_type_for_loop:
      GENERATE_INTERMEDIATE_CODE_PROCESS_EXPRESSION(
        method_record.run_time_code.push(i_return);
        method_record.run_time_code.push(op_ptr[1]);

        // - ERROR -
        if (!(*op_ptr & c_op_modifier_object))
        {
          error_code.push(ei_expected_object_as_operand);
          error_code.push(fgn_ptr[c_fg_for_loop_source_pos]);
        }

        fgn_ptr += c_fg_for_loop_size;
      );
      break;
    case c_fg_type_break:
      fgn_ptr += c_fg_break_size;
      break;
    case c_fg_type_continue:
      fgn_ptr += c_fg_continue_size;
      break;
    case c_fg_type_switch:
      GENERATE_INTERMEDIATE_CODE_PROCESS_EXPRESSION(
        method_record.run_time_code.push(i_return);
        method_record.run_time_code.push(op_ptr[1]);

        // - ERROR -
        if (!(*op_ptr & c_op_modifier_object))
        {
          error_code.push(ei_expected_object_as_operand);
          error_code.push(fgn_ptr[c_fg_switch_source_pos]);
        }

        fgn_ptr += c_fg_switch_size + fgn_ptr[c_fg_switch_default_cnt] + fgn_ptr[c_fg_switch_exp_cnt];
      );
      break;
    default:
      debug_assert(0);
    }
  }
  while(fgn_ptr < fgn_ptr_end);

  // - insert end instruction to begin code -
  method_record.begin_code.push(i_expression_end);

  // - set method stack size -
  method_record.stack_size = im_descr.stack_idx_max;

  // - translation of catch variable names to stack positions -
  if (method_record.try_fg_maps.used != 0)
  {
    try_fg_map_s *tfg_ptr = method_record.try_fg_maps.data;
    try_fg_map_s *tfg_ptr_end = tfg_ptr + method_record.try_fg_maps.used;

    do
    {
      unsigned *fo_ptr = im_descr.found_operands.data + im_descr.var_name_fo_map[tfg_ptr->tfgm_var_idx];
      cassert(*fo_ptr == c_op_modifier_object);
      tfg_ptr->tfgm_var_idx = fo_ptr[1];
    }
    while(++tfg_ptr < tfg_ptr_end);
  }

  return true;
}/*}}}*/

void script_parser_s::generate_intermediate_code()
{/*{{{*/

  // - base constants of different constant types in array of constants  -
  im_descr.cv_char_base = 0;
  im_descr.cv_integer_base = im_descr.cv_char_base + const_chars.used;
  im_descr.cv_float_base = im_descr.cv_integer_base + const_ints.used;
  im_descr.cv_string_base = im_descr.cv_float_base + const_floats.used;
  im_descr.cv_delegate_base = im_descr.cv_string_base + const_strings.used;
  im_descr.cv_type_base = im_descr.cv_delegate_base + const_delegates.used;
  im_descr.cv_count = im_descr.cv_type_base + class_records.used + static_const_element_cnt;

  // - queue for storing indexes of top classes -
  ui_queue_s top_class_queue;
  top_class_queue.init();

  // - find index of non built in classes with no parent -
  if (class_records.used != 0)
  {
    class_record_s *cr_ptr = class_records.data;
    class_record_s *cr_ptr_end = cr_ptr + class_records.used;
    do
    {
      if (!(cr_ptr->modifiers & c_modifier_built_in) && (cr_ptr->parent_record == c_idx_not_exist))
      {
        top_class_queue.insert(cr_ptr - class_records.data);
      }
    }
    while(++cr_ptr < cr_ptr_end);
  }

  // - test if any classes was defined -
  if (top_class_queue.used <= 0)
  {
    top_class_queue.clear();
    return;
  }

  // - queue for storing indexes of searched classes -
  ui_queue_s class_queue;
  class_queue.init();

  im_descr.var_name_fo_map.copy_resize(variable_symbol_names.used);
  im_descr.var_name_fo_map.used = variable_symbol_names.used;

  im_descr.const_idx_fo_map.copy_resize(im_descr.cv_count);
  im_descr.const_idx_fo_map.used = im_descr.cv_count;

  im_descr.static_vi_fo_map.copy_resize(static_element_cnt);
  im_descr.static_vi_fo_map.used = static_element_cnt;

  {
    im_descr.code_modifiers = c_code_modifier_static;
    im_descr.method_idx = c_idx_not_exist;
    im_descr.stack_idx_max = 0;
    im_descr.free_stack_idxs.used = 0;

    do
    {
      unsigned tcr_idx = top_class_queue.next();
      class_queue.insert(tcr_idx);

      // - clear array of identifier operands, and clear of variable name mapping -
      im_descr.found_operands.used = 0;
      memset(im_descr.var_name_fo_map.data,(int)c_idx_not_exist,im_descr.var_name_fo_map.used*sizeof(unsigned));
      memset(im_descr.const_idx_fo_map.data,(int)c_idx_not_exist,im_descr.const_idx_fo_map.used*sizeof(unsigned));
      if (im_descr.static_vi_fo_map.used != 0) {
        memset(im_descr.static_vi_fo_map.data,(int)c_idx_not_exist,im_descr.static_vi_fo_map.used*sizeof(unsigned));
      }

      // - cycle through records of all classes sorted by deep of nesting -
      do
      {
        unsigned cr_idx = class_queue.next();
        class_record_s &class_record = class_records[cr_idx];

        // - set class using namespaces -
        using_namespace_idxs.swap(class_record.using_namespace_idxs);

        im_descr.class_idx = cr_idx;

        ui_array_s &variable_record_idxs = class_record.variable_record_idxs;
        if (variable_record_idxs.used != 0)
        {
          unsigned *vri_ptr = variable_record_idxs.data;
          unsigned *vri_ptr_end = vri_ptr + variable_record_idxs.used;

          // - cycle through all variables -
          do
          {
            variable_record_s &variable_record = variable_records[*vri_ptr];

            // - if variable has initializing expression and is static, then generate intermediate code -
            if ((variable_record.init_expression_idx != c_idx_not_exist) && (variable_record.modifiers & c_modifier_static))
            {
              debug_message_3(fprintf(stderr,"script_parser: intermediate generate: variable initialize expression: %u\n",variable_record.init_expression_idx));

              im_descr.exp_idx = variable_record.init_expression_idx;
              if (!generate_expression_intermediate_code(static_begin_code,static_run_time_code,init_expressions[variable_record.init_expression_idx]))
              {
                // - reset class using namespaces -
                class_record.using_namespace_idxs.swap(using_namespace_idxs);

                class_queue.clear();
                top_class_queue.clear();
                return;
              }

              // - release last operand of expression -
              unsigned *op_ptr = im_descr.operands.data + im_descr.operand_stack.pop();
              if (*op_ptr & c_op_modifier_tmp)
              {
                im_descr.free_stack_idxs.push(op_ptr[1]);
              }
            }
          }
          while(++vri_ptr < vri_ptr_end);
        }

        // - process all child classes -
        ui_array_s &class_record_idxs = class_record.class_record_idxs;

        if (class_record_idxs.used != 0)
        {
          unsigned *cri_ptr = class_record_idxs.data;
          unsigned *cri_ptr_end = cri_ptr + class_record_idxs.used;

          do
          {
            class_queue.insert(*cri_ptr);
          }
          while(++cri_ptr < cri_ptr_end);
        }

        // - reset class using namespaces -
        class_record.using_namespace_idxs.swap(using_namespace_idxs);
      }
      while(class_queue.used > 0);
    }
    while(top_class_queue.used > 0);

    // - insertion of ending instruction to initialization code -
    static_begin_code.push(i_expression_end);
    static_run_time_code.push(i_expression_end);

    // - set stack size -
    stack_size = im_descr.stack_idx_max;
  }

  // - clear classes queue -
  class_queue.clear();

  // - clear top classes queue -
  top_class_queue.clear();

  // - cycle through records of all classes -
  unsigned cr_idx = 0;
  do
  {
    class_record_s &class_record = class_records[cr_idx];

    if (!(class_record.modifiers & c_modifier_built_in))
    {
      im_descr.code_modifiers = c_code_modifier_nothing;
      im_descr.class_idx = cr_idx;
      im_descr.stack_idx_max = 1;

      // - set class using namespaces -
      using_namespace_idxs.swap(class_record.using_namespace_idxs);

      // - generation of intermediate code for initialization of variables that are not static -
      ui_array_s &variable_record_idxs = class_record.variable_record_idxs;
      if (variable_record_idxs.used != 0)
      {
        im_descr.method_idx = c_idx_not_exist;
        im_descr.free_stack_idxs.used = 0;

        // - clear array of identifier operands, and clear of name mapping -
        im_descr.found_operands.used = 0;
        memset(im_descr.var_name_fo_map.data,(int)c_idx_not_exist,im_descr.var_name_fo_map.used*sizeof(unsigned));
        memset(im_descr.const_idx_fo_map.data,(int)c_idx_not_exist,im_descr.const_idx_fo_map.used*sizeof(unsigned));
        if (im_descr.static_vi_fo_map.used != 0) {
          memset(im_descr.static_vi_fo_map.data,(int)c_idx_not_exist,im_descr.static_vi_fo_map.used*sizeof(unsigned));
        }

        unsigned *vri_ptr = variable_record_idxs.data;
        unsigned *vri_ptr_end = vri_ptr + variable_record_idxs.used;

        // - cycle through all variables -
        do
        {
          variable_record_s &variable_record = variable_records[*vri_ptr];

          // - if variable contain initializing expression, then generate its intermediate code -
          if ((variable_record.init_expression_idx != c_idx_not_exist) && !(variable_record.modifiers & c_modifier_static))
          {
            debug_message_3(fprintf(stderr,"script_parser: intermediate generate: variable initialize expression: %u\n",variable_record.init_expression_idx));

            im_descr.exp_idx = variable_record.init_expression_idx;
            if (!generate_expression_intermediate_code(class_record.init_begin_code,class_record.init_run_time_code,init_expressions[variable_record.init_expression_idx]))
            {
              // - reset class using namespaces -
              class_record.using_namespace_idxs.swap(using_namespace_idxs);

              return;
            }

            // - release last operand of expression -
            unsigned *op_ptr = im_descr.operands.data + im_descr.operand_stack.pop();
            if (*op_ptr & c_op_modifier_tmp)
            {
              im_descr.free_stack_idxs.push(op_ptr[1]);
            }
          }
        }
        while(++vri_ptr < vri_ptr_end);

      }

      // - insertion of ending instruction to initialization code -
      class_record.init_begin_code.push(i_expression_end);
      class_record.init_run_time_code.push(i_expression_end);

      // - set stack size -
      class_record.stack_size = im_descr.stack_idx_max;

      // - generation of intermediate code for expressions of class method -
      ui_array_s &method_record_idxs = class_record.method_record_idxs;
      if (method_record_idxs.used != 0)
      {
        unsigned *mri_ptr = method_record_idxs.data;
        unsigned *mri_ptr_end = mri_ptr + method_record_idxs.used;

        // - cycle through all class methods -
        do
        {
          method_record_s &method_record = method_records[*mri_ptr];

          if (!(method_record.modifiers & (c_modifier_abstract | c_modifier_built_in)))
          {
            exp_flow_graph_s &fg = method_flow_graphs[method_record.flow_graph_idx];

            if (fg.expressions.used != 0)
            {
              im_descr.method_idx = *mri_ptr;

              if (method_record.modifiers & c_modifier_static)
              {
                // - set modifier of generated code -
                im_descr.code_modifiers = c_code_modifier_run_time | c_code_modifier_static;

                // - count method parameters on stack -
                im_descr.stack_idx_max = method_record.parameter_record_idxs.used;
              }
              else
              {
                // - set modifiers of generated code -
                im_descr.code_modifiers = c_code_modifier_run_time;

                // - count parameters of methods on stack + this -
                im_descr.stack_idx_max = method_record.parameter_record_idxs.used + 1;
              }

              // - generate method intermediate code -
              if (!generate_method_intermediate_code())
              {
                // - reset class using namespaces -
                class_record.using_namespace_idxs.swap(using_namespace_idxs);

                return;
              }
            }
          }
        }
        while(++mri_ptr < mri_ptr_end);
      }

      // - reset class using namespaces -
      class_record.using_namespace_idxs.swap(using_namespace_idxs);
    }
  }
  while(++cr_idx < class_records.used);

  // - generate code for constant delegates -
  if (const_delegates.used != 0)
  {
    unsigned cd_idx = 0;
    do {
      unsigned method_ri = const_delegates[cd_idx].name_idx_ri;
      method_record_s &method_record = method_records[method_ri];

      // - retrieve method parent index -
      im_descr.class_idx = method_record.parent_record;

      // - retrieve method record index -
      im_descr.method_idx = method_ri;

      // - set modifier of generated code -
      im_descr.code_modifiers = c_code_modifier_run_time | c_code_modifier_static;

      // - count method parameters on stack -
      im_descr.stack_idx_max = method_record.parameter_record_idxs.used;

      // - generate method intermediate code -
      if (!generate_method_intermediate_code())
      {
        return;
      }
    } while(++cd_idx < const_delegates.used);
  }

  im_descr.static_vi_fo_map.clear();
  im_descr.const_idx_fo_map.clear();
  im_descr.var_name_fo_map.clear();
}/*}}}*/

void script_parser_s::process_errors()
{/*{{{*/
  ui_array_s class_stack;
  class_stack.init();

  if (error_code.used != 0)
  {
    unsigned *ei_ptr = error_code.data;
    unsigned *ei_ptr_end = ei_ptr + error_code.used;
    unsigned error_idx = 1;

    do
    {
      unsigned source_pos = GET_SRC_POS(ei_ptr[1]);
      source_s &source = sources[GET_SRC_IDX(ei_ptr[1])];

      fprintf(stderr," ---------------------------------------- \n");

      switch (*ei_ptr)
      {
      case ei_unrecognizable_terminal:
        fprintf(stderr,"%u. PARSE ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_show_line(source.source_string,source_pos);
        fprintf(stderr,"Unrecognizable input terminal\n");

        ei_ptr += 2;
        break;
      case ei_wrong_program_syntax:
        fprintf(stderr,"%u. PARSE ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_show_line(source.source_string,source_pos);
        fprintf(stderr,"Wrong program syntax\n");

        ei_ptr += 2;
        break;
      case ei_duplicate_class_element_name:
        fprintf(stderr,"%u. PARSE_ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_show_line(source.source_string,source_pos);
        fprintf(stderr,"Duplicate element ");
        print_class_sequence(class_symbol_names,class_records,class_stack,ei_ptr[2]);
        fprintf(stderr,"%s\n",variable_symbol_names[ei_ptr[3]].data);

        ei_ptr += 4;
        break;
      case ei_duplicate_class_method_name:
        fprintf(stderr,"%u. PARSE_ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_show_line(source.source_string,source_pos);
        fprintf(stderr,"Duplicate method ");
        print_class_sequence(class_symbol_names,class_records,class_stack,ei_ptr[2]);
        fprintf(stderr,"%s\n",method_symbol_names[ei_ptr[3]].data);

        ei_ptr += 4;
        break;
      case ei_duplicate_class_name:
        fprintf(stderr,"%u. PARSE_ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_show_line(source.source_string,source_pos);
        fprintf(stderr,"Duplicate class ");
        print_class_sequence(class_symbol_names,class_records,class_stack,ei_ptr[2]);
        fprintf(stderr,"%s\n",class_symbol_names[ei_ptr[3]].data);

        ei_ptr += 4;
        break;
      case ei_duplicate_method_parameter:
        fprintf(stderr,"%u. PARSE_ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_show_line(source.source_string,source_pos);
        fprintf(stderr,"Duplicate method parameter %s\n",variable_symbol_names[ei_ptr[2]].data);

        ei_ptr += 3;
        break;
      case ei_variable_ilegall_modifier:
      {
        variable_record_s &variable_record = variable_records[ei_ptr[2]];

        fprintf(stderr,"%u. PARSE_ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_show_line(source.source_string,source_pos);
        fprintf(stderr,"Illegal modifier of element ");
        print_class_sequence(class_symbol_names,class_records,class_stack,ei_ptr[3]);
        fprintf(stderr,"%s\n",variable_symbol_names[variable_record.name_idx].data);

        ei_ptr += 4;
      }
      break;
      case ei_variable_modifier_private_and_public:
        fprintf(stderr,"%u. PARSE_ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_show_line(source.source_string,source_pos);
        fprintf(stderr,"The element modifiers can be set to public or private not both\n");

        ei_ptr += 2;
        break;
      case ei_class_ilegall_modifier:
      {
        class_record_s &class_record = class_records[ei_ptr[2]];

        fprintf(stderr,"%u. PARSE_ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_show_line(source.source_string,source_pos);
        fprintf(stderr,"Illegal modifier for class ");
        print_class_sequence(class_symbol_names,class_records,class_stack,ei_ptr[3]);
        fprintf(stderr,"%s\n",class_symbol_names[class_record.name_idx].data);

        ei_ptr += 4;
      }
      break;
      case ei_class_modifier_abstract_and_final:
        fprintf(stderr,"%u. PARSE_ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_show_line(source.source_string,source_pos);
        fprintf(stderr,"The class modifiers can be set to abstract or final, not both\n");

        ei_ptr += 2;
        break;
      case ei_method_modifier_private_and_public:
        fprintf(stderr,"%u. PARSE_ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_show_line(source.source_string,source_pos);
        fprintf(stderr,"The method modifiers can be set to public or private not both\n");

        ei_ptr += 2;
        break;
      case ei_method_modifier_abstract_and_static_or_final:
        fprintf(stderr,"%u. PARSE_ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_show_line(source.source_string,source_pos);
        fprintf(stderr,"The abstract method modifiers cannot be set to static or final\n");

        ei_ptr += 2;
        break;
      case ei_method_modifier_parallel_must_be_static:
        fprintf(stderr,"%u. PARSE_ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_show_line(source.source_string,source_pos);
        fprintf(stderr,"Parallel method must be defined with static modifier\n");

        ei_ptr += 2;
        break;
      case ei_constructor_ilegall_modifier:
        fprintf(stderr,"%u. PARSE_ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_show_line(source.source_string,source_pos);
        fprintf(stderr,"Ilegall constructor modifiers (private, static, abstract or parallel)\n");

        ei_ptr += 2;
        break;
      case ei_abstract_method_no_abstract_class:
      {
        method_record_s &method_record = method_records[ei_ptr[2]];

        fprintf(stderr,"%u. PARSE_ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_show_line(source.source_string,source_pos);
        fprintf(stderr,"The abstract method ");
        print_class_sequence(class_symbol_names,class_records,class_stack,ei_ptr[3]);
        fprintf(stderr,"%s defined in non abstract class\n", method_symbol_names[method_record.name_idx].data);

        ei_ptr += 4;
      }
      break;
      case ei_non_abstract_method_without_body:
      {
        method_record_s &method_record = method_records[ei_ptr[2]];

        fprintf(stderr,"%u. PARSE_ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_show_line(source.source_string,source_pos);
        fprintf(stderr,"Non abstract method ");
        print_class_sequence(class_symbol_names,class_records,class_stack,ei_ptr[3]);
        fprintf(stderr,"%s require body instead of semicolon\n",method_symbol_names[method_record.name_idx].data);

        ei_ptr += 4;
      }
      break;
      case ei_abstract_method_with_body:
      {
        method_record_s &method_record = method_records[ei_ptr[2]];

        fprintf(stderr,"%u. PARSE_ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_show_line(source.source_string,source_pos);
        fprintf(stderr,"Abstract method ");
        print_class_sequence(class_symbol_names,class_records,class_stack,ei_ptr[3]);
        fprintf(stderr,"%s do not require body\n",method_symbol_names[method_record.name_idx].data);

        ei_ptr += 4;
      }
      break;
      case ei_break_continue_without_enclosing_loop:
        fprintf(stderr,"%u. PARSE_ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_show_line(source.source_string,source_pos);
        fprintf(stderr,"Keyword %s is not included in any loop\n",ei_ptr[2]?"continue":"break");

        ei_ptr += 3;
        break;
      case ei_break_continue_as_single_loop_action:
        fprintf(stderr,"%u. PARSE_ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_show_line(source.source_string,source_pos);
        fprintf(stderr,"Keyword %s used as single action in loop\n",ei_ptr[2]?"continue":"break");

        ei_ptr += 3;
        break;
      case ei_break_continue_from_switch_case:
        fprintf(stderr,"%u. PARSE_ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_show_line(source.source_string,source_pos);
        fprintf(stderr,"Keyword %s exits from switch case\n",ei_ptr[2]?"continue":"break");

        ei_ptr += 3;
        break;
      case ei_empty_try_block_for_catch:
        fprintf(stderr,"%u. PARSE_ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_show_line(source.source_string,source_pos);
        fprintf(stderr,"Empty try block for catch statement\n");

        ei_ptr += 2;
        break;
      case ei_module_duplicate_class_element_name:
        fprintf(stderr,"%u. ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_show_line(source.source_string,source_pos);
        fprintf(stderr,"Duplicate element ");
        print_class_sequence(class_symbol_names,class_records,class_stack,ei_ptr[2]);
        fprintf(stderr,"%s defined in module\n",variable_symbol_names[ei_ptr[3]].data);

        ei_ptr += 4;
        break;
      case ei_module_duplicate_class_method_name:
        fprintf(stderr,"%u. ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_show_line(source.source_string,source_pos);
        fprintf(stderr,"Duplicate method ");
        print_class_sequence(class_symbol_names,class_records,class_stack,ei_ptr[2]);
        fprintf(stderr,"%s defined in module\n",method_symbol_names[ei_ptr[3]].data);

        ei_ptr += 4;
        break;
      case ei_module_duplicate_class_name:
        fprintf(stderr,"%u. ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_show_line(source.source_string,source_pos);
        fprintf(stderr,"Duplicate class \"%s\" defined in module\n",class_symbol_names[ei_ptr[2]].data);

        ei_ptr += 3;
        break;
      case ei_module_cannot_find_remote_class:
        fprintf(stderr,"%u. ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_show_line(source.source_string,source_pos);
        fprintf(stderr,"Cannot find remote class required by module \"%s\"\n",module_names[ei_ptr[2]].data);

        ei_ptr += 3;
        break;
      case ei_module_initialize_error:
        fprintf(stderr,"%u. ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_show_line(source.source_string,source_pos);
        fprintf(stderr,"Error while initializing module \"%s\"\n",module_names[ei_ptr[2]].data);

        ei_ptr += 3;
        break;
      case ei_cannot_find_module:
        fprintf(stderr,"%u. ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_show_line(source.source_string,source_pos);
        fprintf(stderr,"Cannot import module \"%s\"\n",module_names[ei_ptr[2]].data);

        ei_ptr += 3;
        break;
      case ei_cannot_resolve_extended_class:
        fprintf(stderr,"%u. ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_line(source.source_string,source_pos);
        fprintf(stderr,"\nCannot resolve extended class %s\n",class_symbol_names[ei_ptr[2]].data);

        ei_ptr += 3;
        break;
      case ei_class_cannot_extend_itself:
        fprintf(stderr,"%u. ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_show_line(source.source_string,source_pos);
        fprintf(stderr,"Class cannot extend itself\n");

        ei_ptr += 2;
        break;
      case ei_cannot_extend_final_class:
        fprintf(stderr,"%u. ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_show_line(source.source_string,source_pos);
        fprintf(stderr,"Extended class %s is defined as final\n",class_symbol_names[ei_ptr[2]].data);

        ei_ptr += 3;
        break;
      case ei_must_implement_inherited_abstract_method:
      {
        class_record_s &e_class_record = class_records[ei_ptr[2]];
        method_record_s &method_record = method_records[ei_ptr[3]];

        fprintf(stderr,"%u. ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_show_line(source.source_string,source_pos);
        fprintf(stderr,"Class %s must implement inherited abstract method %s.%s\n",
                class_symbol_names[e_class_record.name_idx].data,
                class_symbol_names[class_records[method_record.parent_record].name_idx].data,
                method_symbol_names[method_record.name_idx].data);

        ei_ptr += 4;
      }
      break;
      case ei_cannot_override_final_method:
      {
        method_record_s &r_method_record = method_records[ei_ptr[2]];
        method_record_s &method_record = method_records[ei_ptr[3]];

        fprintf(stderr,"%u. ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_show_line(source.source_string,source_pos);
        fprintf(stderr,"Class %s cannot override final method ",
                class_symbol_names[class_records[r_method_record.parent_record].name_idx].data);
        print_class_sequence(class_symbol_names,class_records,class_stack,method_record.parent_record);
        fprintf(stderr,"%s\n",method_symbol_names[method_record.name_idx].data);

        ei_ptr += 4;
      }
      break;
      case ei_class_does_not_contain_method:
      {
        class_record_s &class_record = class_records[ei_ptr[2]];

        fprintf(stderr,"%u. ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_line(source.source_string,source_pos);
        fprintf(stderr,"\nClass ");
        print_class_sequence(class_symbol_names,class_records,class_stack,class_record.parent_record);
        fprintf(stderr,"%s does not contain method %s\n",class_symbol_names[class_record.name_idx].data,method_symbol_names[ei_ptr[3]].data);

        ei_ptr += 4;
      }
      break;
      case ei_class_does_not_have_constructor:
      {
        class_record_s &class_record = class_records[ei_ptr[2]];

        fprintf(stderr,"%u. ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_line(source.source_string,source_pos);
        fprintf(stderr,"\nClass ");
        print_class_sequence(class_symbol_names,class_records,class_stack,class_record.parent_record);
        fprintf(stderr,"%s does not have constructor %s\n",class_symbol_names[class_record.name_idx].data,method_symbol_names[ei_ptr[3]].data);

        ei_ptr += 4;
      }
      break;
      case ei_class_does_not_contain_variable:
      {
        class_record_s &class_record = class_records[ei_ptr[2]];

        fprintf(stderr,"%u. ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_line(source.source_string,source_pos);
        fprintf(stderr,"\nClass ");
        print_class_sequence(class_symbol_names,class_records,class_stack,class_record.parent_record);
        fprintf(stderr,"%s does not contain variable %s\n",class_symbol_names[class_record.name_idx].data,variable_symbol_names[ei_ptr[3]].data);

        ei_ptr += 4;
      }
      break;
      case ei_static_reference_to_nonstatic_method:
      {
        method_record_s &method_record = method_records[ei_ptr[2]];

        fprintf(stderr,"%u. ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_line(source.source_string,source_pos);
        fprintf(stderr,"\nStatic reference to non-static method ");
        print_class_sequence(class_symbol_names,class_records,class_stack,method_record.parent_record);
        fprintf(stderr,"%s\n",method_symbol_names[method_record.name_idx].data);

        ei_ptr += 3;
      }
      break;
      case ei_cannot_access_private_method:
      {
        method_record_s &method_record = method_records[ei_ptr[2]];

        fprintf(stderr,"%u. ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_line(source.source_string,source_pos);
        fprintf(stderr,"\nCannot access private method ");
        print_class_sequence(class_symbol_names,class_records,class_stack,method_record.parent_record);
        fprintf(stderr,"%s\n",method_symbol_names[method_record.name_idx].data);

        ei_ptr += 3;
      }
      break;
      case ei_static_reference_to_nonstatic_variable:
      {
        variable_record_s &variable_record = variable_records[ei_ptr[2]];

        fprintf(stderr,"%u. ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_line(source.source_string,source_pos);
        fprintf(stderr,"\nStatic reference to non-static variable ");
        print_class_sequence(class_symbol_names,class_records,class_stack,variable_record.parent_record);
        fprintf(stderr,"%s\n",variable_symbol_names[variable_record.name_idx].data);

        ei_ptr += 3;
      }
      break;
      case ei_cannot_access_private_variable:
      {
        variable_record_s &variable_record = variable_records[ei_ptr[2]];

        fprintf(stderr,"%u. ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_line(source.source_string,source_pos);
        fprintf(stderr,"\nCannot access private variable ");
        print_class_sequence(class_symbol_names,class_records,class_stack,variable_record.parent_record);
        fprintf(stderr,"%s\n",variable_symbol_names[variable_record.name_idx].data);

        ei_ptr += 3;
      }
      break;
      case ei_namespace_name_cannot_be_resolved:
        fprintf(stderr,"%u. ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_line(source.source_string,source_pos);
        fprintf(stderr,"\nNamespace name %s cannot be resolved\n",class_symbol_names[ei_ptr[2]].data);

        ei_ptr += 3;
        break;
      case ei_class_name_cannot_be_resolved:
        fprintf(stderr,"%u. ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_line(source.source_string,source_pos);
        fprintf(stderr,"\nClass name %s cannot be resolved\n",class_symbol_names[ei_ptr[2]].data);

        ei_ptr += 3;
        break;
      case ei_variable_name_cannot_be_resolved:
        fprintf(stderr,"%u. ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_line(source.source_string,source_pos);
        fprintf(stderr,"\nVariable name %s cannot be resolved\n",variable_symbol_names[ei_ptr[2]].data);

        ei_ptr += 3;
        break;
      case ei_cannot_use_this_in_static_code:
        fprintf(stderr,"%u. ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_line(source.source_string,source_pos);
        fprintf(stderr,"\nCannot use keyword \"this\" in static code\n");

        ei_ptr += 2;
        break;
      case ei_cannot_create_abstract_class_object:
      {
        class_record_s &class_record = class_records[ei_ptr[2]];

        fprintf(stderr,"%u. ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_line(source.source_string,source_pos);
        fprintf(stderr,"\nCannot create object of abstract class ");
        print_class_sequence(class_symbol_names,class_records,class_stack,class_record.parent_record);
        fprintf(stderr,"%s\n",class_symbol_names[class_record.name_idx].data);

        ei_ptr += 3;
      }
      break;
      case ei_expected_object_as_operand:
        fprintf(stderr,"%u. ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_line(source.source_string,source_pos);
        fprintf(stderr,"\nExpected object instance, not static reference\n");

        ei_ptr += 2;
        break;
      case ei_switch_expect_objects_as_operands:
        fprintf(stderr,"%u. ERROR: in file: \"%s\" on line: %u\n",error_idx,source.file_name.data,source.source_string.get_character_line(source_pos));
        print_error_line(source.source_string,source_pos);
        fprintf(stderr,"\nIn switch statement are expected object instances, not static references\n");

        ei_ptr += 2;
        break;
      default:
        cassert(0);
      }
    }
    while(++error_idx,ei_ptr < ei_ptr_end);

    fprintf(stderr," ---------------------------------------- \n");

  }

  class_stack.clear();
}/*}}}*/

/*
 * global functions
 */

void print_error_show_line(string_s &source_string,unsigned begin)
{/*{{{*/
  debug_assert(begin < source_string.size);

  // - find begin of line -
  char *lb_ptr = source_string.data + source_string.get_character_line_begin(begin);
  char *le_ptr = source_string.data + source_string.get_character_line_end(begin);

  char tmp_char = *le_ptr;
  *le_ptr = '\0';
  fprintf(stderr,"%s\n",lb_ptr);
  *le_ptr = tmp_char;

  unsigned space_cnt = source_string.get_print_size_between(lb_ptr - source_string.data,begin);
  if (space_cnt != 0)
  {
    unsigned idx = 0;
    do
    {
      fputc(' ',stderr);
    }
    while(++idx < space_cnt);
  }

  fputc('^',stderr);
  fputc('\n',stderr);
}/*}}}*/

void print_error_line(string_s &source_string,unsigned char_pos)
{/*{{{*/
  debug_assert(char_pos < source_string.size);

  // - find begin of lines -
  char *lb_ptr = source_string.data + source_string.get_character_line_begin(char_pos);
  char *le_ptr = source_string.data + source_string.get_character_line_end(char_pos);

  char tmp_char = *le_ptr;
  *le_ptr = '\0';
  fprintf(stderr,"%s\n",lb_ptr);
  *le_ptr = tmp_char;
}/*}}}*/

void print_class_sequence(string_rb_tree_s &class_symbol_names,class_records_s &class_records,ui_array_s &class_stack,unsigned class_record_idx)
{/*{{{*/
  if (class_record_idx == c_idx_not_exist)
  {
    return;
  }

  debug_assert(class_record_idx < class_records.used);
  class_stack.used = 0;

  unsigned class_idx = class_record_idx;
  do
  {
    class_record_s &class_record = class_records[class_idx];

    class_stack.push(class_record.name_idx);
    class_idx = class_record.parent_record;
  }
  while(class_idx != c_idx_not_exist);

  unsigned *ni_ptr = class_stack.data + class_stack.used - 1;
  unsigned *ni_ptr_end = class_stack.data;

  do
  {
    fprintf(stderr,"%s.",class_symbol_names[*ni_ptr].data);
  }
  while(--ni_ptr >= ni_ptr_end);
}/*}}}*/

