/* ramachandran.cpp: ramachandran plot class */
//C Copyright (C) 2000-2004 Kevin Cowtan and University of York
//C Copyright (C) 2000-2005 Kevin Cowtan and University of York
//L
//L  This library is free software and is distributed under the terms
//L  and conditions of version 2.1 of the GNU Lesser General Public
//L  Licence (LGPL) with the following additional clause:
//L
//L     `You may also combine or link a "work that uses the Library" to
//L     produce a work containing portions of the Library, and distribute
//L     that work under terms of your choice, provided that you give
//L     prominent notice with each copy of the work that the specified
//L     version of the Library is used in it, and that you include or
//L     provide public access to the complete corresponding
//L     machine-readable source code for the Library including whatever
//L     changes were used in the work. (i.e. If you make changes to the
//L     Library you must distribute those, but you do not need to
//L     distribute source or object code to those portions of the work
//L     not covered by this licence.)'
//L
//L  Note that this clause grants an additional right and does not impose
//L  any additional restriction, and so does not affect compatibility
//L  with the GNU General Public Licence (GPL). If you wish to negotiate
//L  other terms, please contact the maintainer.
//L
//L  You can redistribute it and/or modify the library under the terms of
//L  the GNU Lesser General Public License as published by the Free Software
//L  Foundation; either version 2.1 of the License, or (at your option) any
//L  later version.
//L
//L  This library is distributed in the hope that it will be useful, but
//L  WITHOUT ANY WARRANTY; without even the implied warranty of
//L  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//L  Lesser General Public License for more details.
//L
//L  You should have received a copy of the CCP4 licence and/or GNU
//L  Lesser General Public License along with this library; if not, write
//L  to the CCP4 Secretary, Daresbury Laboratory, Warrington WA4 4AD, UK.
//L  The GNU Lesser General Public can also be obtained by writing to the
//L  Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston,
//L  MA 02111-1307 USA


#include "ramachandran.h"


namespace clipper {

namespace data {

  int rama_data_size = 36;
  ftype32 rama_gly[] = {
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     1,    9,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,// 0
     0,    0,    0,    0,    0,    0,    0,    7,    1,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    7,
     0,    2,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,// 1
     0,    0,    0,    0,    0,    0,    0,    3,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    5,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,// 2
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    3,
     3,    0,    0,    0,    0,    0,    0,    0,    3,    3,    0,    0,// 3
     0,    0,    0,   11,   37,   21,   10,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    4,   15,   18,   74,
    36,    3,    5,    2,    0,    0,    0,    0,    3,    3,    0,    0,// 4
     1,    3,   30,  146,  193,  137,   30,    6,    0,    0,    0,    0,
     0,    0,    0,    0,    1,    0,    0,    1,   16,   60,  237,  329,
   131,   25,    7,    2,    0,    3,    2,    0,    0,    0,    0,    1,// 5
    42,  154,  432,  857,  603,  201,   52,    3,    0,    0,    0,    0,
     3,    8,    0,    3,    8,    8,   49,   97,  204,  334,  409,  593,
   320,   63,   11,    0,    0,    4,    3,    0,    0,    2,    5,   15,// 6
   616, 1527, 1975, 1407,  577,  144,   51,    0,    0,    0,    0,    0,
     1,    0,    0,    5,   34,   93,  178,  366,  452,  310,  236,  305,
   210,   53,   22,   16,    3,    2,    0,    0,    7,    9,   26,  111,// 7
  2655, 2916, 2032,  816,  205,   61,   14,   10,    5,    2,    7,   11,
    13,    5,   19,   73,  171,  337,  524,  493,  460,  222,  127,   97,
    57,   28,   21,   12,    4,   19,   31,   29,   24,   41,  196, 1032,// 8
  2461, 1984,  840,  240,   74,   29,   16,    5,   10,   15,   15,   22,
    23,   40,   75,  253,  356,  406,  464,  420,  289,  144,   53,   24,
    20,   19,   15,   15,    0,   19,   26,   30,   41,  145,  798, 1998,// 9
  1122,  937,  278,   55,   30,    6,   16,    6,   19,   12,   29,   39,
    51,   83,  119,  216,  327,  228,  292,  250,  168,  101,   47,   32,
     9,   19,    6,    9,   12,    0,    9,   30,   40,  218,  929, 1231,//10
   467,  301,  148,   54,    6,    3,    3,    0,    6,    2,   26,   28,
    41,   50,   66,  173,  205,  172,  190,  206,  112,   45,   17,   22,
     2,   12,   11,    7,    3,    0,    5,   12,   58,  195,  402,  443,//11
   190,  104,   33,   19,   24,   10,    5,    0,    1,   10,   17,   15,
    29,   36,   71,   87,  127,  173,  156,  135,   68,   48,   32,   13,
     7,   16,    5,    4,    7,    1,   16,   13,   16,   86,  102,  111,//12
    64,   32,   12,   11,   32,    9,    0,    0,    0,    7,    8,   11,
    10,   38,   43,   61,   86,  106,  112,  140,  132,   67,   40,   15,
     9,   12,    1,    0,   13,   10,    2,   11,   11,   24,   68,  101,//13
    15,   11,    9,    2,    3,    1,    0,    0,    0,    2,    3,    0,
    14,    9,   28,   45,  101,  102,  169,  169,  162,  112,   60,   18,
     2,    1,    0,    0,    5,    2,    0,   10,   16,   15,   26,   36,//14
     7,   12,    5,    0,    0,    0,    0,    0,    0,    2,    5,    4,
    10,    4,   31,   40,   76,  139,  259,  193,  137,  116,   51,   18,
     4,    0,    0,    1,    0,    4,    6,    1,   21,    8,   11,   18,//15
     4,    8,    0,    0,    0,    0,    0,    1,   12,    0,    1,    6,
     0,    7,    6,   27,   93,  150,  202,  253,  211,  105,   30,   23,
     6,    5,    3,    8,    1,   17,   16,    0,    0,    1,    3,   10,//16
     0,    0,    0,    0,    0,    6,    1,   10,    0,    0,    1,    6,
     9,    6,    9,   30,  104,  187,  324,  399,  208,  126,   48,   19,
    12,    6,    3,    0,    0,    3,    1,    0,    0,    0,    0,    0,//17
     0,    2,    1,    0,    0,    6,    0,    0,    0,    0,    0,   10,
    10,   16,   38,   35,  153,  303,  421,  352,  184,   72,   54,   19,
    21,    8,    7,    0,    0,    0,    0,    5,    4,    1,    0,    1,//18
     4,    6,    3,    0,    1,    3,    1,    9,    0,    0,    0,    3,
     3,   18,   38,   72,  191,  401,  430,  252,  172,   74,   40,    9,
     9,    0,   11,    6,    7,    0,    0,    3,   12,   10,    2,    8,//19
    18,    1,    0,    3,   12,    8,   11,    3,    0,    2,    0,    0,
     1,   23,   71,  164,  338,  358,  286,  185,  125,   46,   17,    5,
     1,    7,    4,   10,    2,    0,    0,    0,    0,    1,    0,    1,//20
     4,   14,   12,    6,    5,    4,    0,    0,    2,    8,    0,    1,
    14,   39,   97,  183,  245,  212,  178,  143,  107,   51,   36,   13,
    11,    1,    4,    7,    0,    0,    0,    0,    0,    0,    0,    0,//21
     7,   21,   18,   46,   23,    4,   10,    1,    0,    0,    0,    6,
    25,   62,  150,  258,  187,  143,  150,  125,   62,   16,   35,   17,
    14,    7,    4,    1,    3,    6,    0,    0,    0,    1,    6,    2,//22
    24,   31,   34,   55,   25,   13,    9,    4,    0,    0,    1,   20,
    40,   82,  144,  259,  208,  150,  148,  151,   88,   50,   33,   26,
    25,   11,    7,   14,    8,    4,   14,    0,    0,   10,   19,   21,//23
    24,   61,   51,   26,   24,    5,    6,    2,    0,    0,    0,   15,
    42,  107,  142,  154,  151,  140,  113,  141,   96,   76,   31,   22,
     9,   16,   19,   13,    7,    8,   12,    1,    0,    4,   23,   28,//24
    86,  126,  147,   42,   16,   27,   25,    3,    0,    1,    3,   35,
    54,   94,  145,  114,  153,  147,  180,  151,  129,  114,   86,   33,
    24,   31,   22,   22,   25,   11,   24,    6,    9,   20,   24,   40,//25
   244,  273,  176,   62,    6,   16,   20,    6,    1,    4,   31,   58,
    80,   90,  107,  157,  181,  206,  254,  225,  269,  151,  100,   87,
    41,   43,   30,   20,   18,   24,   10,    1,   10,   34,   73,  137,//26
   499,  309,  145,   71,   18,   30,   21,   36,   30,   25,   22,   43,
    45,  132,  180,  216,  225,  325,  436,  455,  378,  138,   72,   51,
    21,   37,   28,    3,   17,   26,    5,   21,   32,   79,  158,  357,//27
   463,  119,   15,   44,   15,   33,   40,   30,   24,   27,   19,   35,
    53,  113,  225,  313,  425,  594,  531,  432,  223,   92,   34,    8,
     0,    5,    4,    7,    8,   13,   28,  104,  249,  318,  354,  531,//28
   174,   21,    1,    0,    1,   17,   10,    3,    4,   13,   20,   23,
    72,  120,  275,  490,  579,  477,  271,  124,   48,   17,    2,    0,
     0,    0,    8,    7,    0,   13,   91,  851, 2514, 1280,  752,  630,//29
    36,    3,    7,    1,    0,    1,    0,    0,    0,    0,    1,    5,
    48,  158,  339,  299,  137,  111,   57,   29,    2,    1,    0,    0,
     0,    0,    0,    0,    0,   11,  179, 2348, 4535, 1658,  748,  240,//30
     4,    0,   16,    1,    0,    0,    0,    0,    0,    0,    5,   12,
    14,   74,  122,   40,    1,   10,    7,    2,    0,    0,    0,    0,
     0,    0,    0,    0,   10,   12,  140,  626,  736,  309,   95,   15,//31
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    2,    1,
    13,    6,    4,    0,    0,    0,   11,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    4,   10,   60,   85,   28,    8,    0,    0,//32
     0,    0,    0,    0,    0,    3,    9,    0,    0,    0,    0,    0,
     3,    9,    3,    6,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,   11,   10,    5,    6,    5,    0,    0,    0,    0,//33
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    5,    7,    3,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,   10,    4,    0,    0,    0,    0,    0,    0,    0,//34
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,//35
  };
  ftype32 rama_pro[] = {
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,// 0
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,// 1
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,// 2
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,// 3
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,// 4
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,// 5
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,// 6
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,// 7
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,// 8
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,// 9
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,//10
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,//11
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,//12
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,//13
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,//14
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,//15
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,//16
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,//17
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,//18
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,//19
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,//20
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,//21
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,//22
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,//23
     0,    0,    0,    0,    0,    2,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,//24
     3,    7,    8,    8,   18,   16,    7,    0,    0,    0,    0,    0,
     0,    0,    3,    7,   11,   11,    6,    4,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,//25
    89,   84,   65,   44,    8,    7,   10,    0,    0,    0,    0,    4,
    23,   29,   25,   34,   70,   44,   34,    9,    0,    0,    0,    1,
     3,    0,    0,    0,    0,    0,    0,    0,    0,    0,    9,   47,//26
   245,  142,  121,   55,   11,   26,   52,   86,   22,   15,   15,   16,
    45,   95,  111,  269,  327,  234,  109,   37,    3,    2,    2,    2,
     6,    0,    0,    0,    0,    0,    0,    0,    0,    9,  122,  217,//27
   399,  100,   43,   21,   45,  111,  203,  246,  126,   59,   69,   61,
   149,  349,  658, 1240, 1354,  828,  239,   58,   16,   12,    7,    6,
     1,    4,    2,    0,    0,    0,    0,    0,   28,  138,  434,  704,//28
   309,   35,   10,    3,   10,   67,  101,   68,   42,   34,   26,   75,
   280,  912, 2196, 3282, 2681, 1103,  162,   21,    3,    1,    1,    2,
    11,    4,    2,    4,    2,    1,    7,   45,  400, 1155, 1852, 1359,//29
    62,    9,    2,    5,    4,    3,    8,    0,    0,    9,   36,   37,
   404, 1893, 3871, 3571, 1491,  290,   38,   11,    0,    0,    0,    0,
     0,    0,    0,    4,    2,   14,   48,  615, 2889, 4269, 2608,  601,//30
     0,    4,    3,    0,    0,    0,    0,    0,    0,    4,   14,   19,
   366, 1302, 1543,  683,  130,    8,    1,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    3,   93,  961, 2346, 1684,  400,   18,//31
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    3,   20,
    82,  119,   85,   14,    1,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,   19,   81,  230,  242,   85,   11,    0,//32
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   10,   11,
     8,    2,    5,    3,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    4,    0,    0,    5,   33,   31,    4,    1,    0,    0,//33
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    3,    6,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    8,    0,    0,    0,    2,    3,    0,    0,    0,    0,//34
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,//35
  };
  ftype32 rama_ngp[] = {
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    4,    0,    0,    2,    3,    0,    0,    0,    0,// 0
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    1,    7,    5,    2,    0,    0,    0,    0,    0,    0,// 1
     0,    0,    0,    0,    0,    3,    4,    0,    0,    0,    0,    0,
     0,    5,    4,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    3,    1,    3,    8,    0,    0,    0,    0,// 2
     0,    0,    0,    0,    1,   26,   46,   23,    2,    1,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     1,   10,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,// 3
     0,    0,    1,   14,  170,  518,  444,  135,   18,    3,    4,    5,
     0,    0,    0,    0,    0,    0,    0,    0,    1,    7,   10,   29,
    22,    6,    5,    0,    0,    0,    0,    0,    0,    0,    0,    0,// 4
     0,    7,  164,  821, 2467, 2335,  972,  229,   38,    7,   10,    8,
     0,    0,    0,    0,    0,    0,    0,    1,    4,   29,   51,  157,
    87,   29,   22,    0,    0,    0,    0,    0,    0,    5,    2,    0,// 5
    46,  354, 1203, 2297, 2859, 1352,  417,  140,   36,    3,   19,   19,
     3,    0,    0,    1,    2,    7,   29,    9,   36,   49,   58,   85,
    90,   45,   22,    1,    3,   14,   22,   11,   18,   16,   15,   10,// 6
   276,  752,  962,  848,  373,   77,   42,   30,   15,    5,   10,   10,
     9,    3,    6,    8,   14,   16,   42,   15,    9,   13,   11,   10,
    16,   14,    8,    0,    2,   26,   99,   65,   35,   12,   32,   65,// 7
   166,  207,  109,   52,    7,   10,    9,   15,   17,    5,    5,    7,
     3,    6,   18,   22,   16,    7,    3,    1,    0,    0,    1,    0,
     0,    0,    0,    0,    0,    7,   33,   39,   17,    6,   21,  111,// 8
    18,   15,    0,    0,    0,    3,    6,    1,   12,    0,   10,    1,
     9,   11,    5,    8,    1,    0,    0,    0,    2,   10,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    1,    0,    0,    2,   14,// 9
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,//10
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    4,    1,//11
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    5,    2,//12
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    1,    4,    0,    0,    0,//13
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    5,   14,    3,    1,    0,//14
     0,    0,    0,    0,    0,    5,    3,    0,    0,    0,    0,    3,
     8,    9,    0,    0,    0,    0,    0,    1,    1,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    0,    7,    2,    0,//15
     0,    0,    0,    0,    0,    3,    2,    0,    0,    0,    0,    0,
     0,    3,    0,    0,    0,    0,    0,    4,    6,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,    3,    1,    0,    0,//16
     0,    0,    0,    0,    0,    0,    0,    0,    3,    3,    0,    0,
     0,    0,    6,   16,   12,   16,    3,    0,    1,    2,    0,    0,
     0,    0,    0,    0,    0,    5,    2,    0,    5,    2,    0,    0,//17
     0,    0,    0,    0,    0,    0,    0,    4,    5,    7,    8,    5,
     4,   11,   36,   74,  164,  192,   69,   20,    4,    7,    0,    0,
     0,    0,    0,    0,    0,    7,    3,    0,    0,    0,    0,    0,//18
     2,    2,    3,    1,    3,    7,    9,   23,   37,   57,   40,   35,
    62,  161,  397,  884, 1539, 1299,  524,  153,   31,    8,    0,    0,
     0,    1,    6,    0,    0,    5,    3,    0,    0,    0,    0,    0,//19
    16,   22,   24,   18,   31,   41,   55,  135,  119,  122,  187,  269,
   365,  760, 1462, 2646, 4068, 2973, 1140,  323,   91,   27,    2,    0,
     1,    2,   16,    2,   20,   13,   11,    2,    8,    9,    5,    2,//20
    65,  105,  141,   97,  107,  112,  206,  297,  260,  302,  376,  583,
   976, 1843, 3301, 4919, 5142, 3134, 1234,  421,  112,   36,   12,    2,
     5,   15,    9,    9,   13,   42,   22,   11,   15,   40,   34,   36,//21
   215,  326,  337,  260,  286,  224,  427,  636,  531,  416,  627, 1304,
  2420, 4039, 5543, 6810, 6445, 3344, 1056,  322,  109,   11,   10,   11,
    15,   17,    3,   19,   33,   92,   76,   61,   39,   78,  103,  174,//22
   807,  852,  845,  653,  539,  340,  574, 1144, 1005,  652,  999, 2377,
  5342, 8103, 7864, 7454, 6508, 3025,  893,  281,  109,   29,   13,   17,
    29,   18,   15,   42,   72,   91,  122,  192,  213,  318,  367,  670,//23
  1774, 1897, 1793, 1122,  556,  188,  227,  471,  600,  823, 1461, 3182,
  7185,10522, 7989, 5999, 4607, 1941,  688,  286,  147,   58,   60,   21,
    49,   29,   27,   68,   76,  128,  222,  341,  383,  670, 1032, 1362,//24
  2961, 3726, 2711, 1208,  435,  157,  106,   90,  221,  646, 1795, 4095,
  8039, 9609, 6837, 4629, 3183, 1428,  604,  199,   87,   32,   29,    7,
    19,   30,   48,   55,   93,  136,  278,  545,  710, 1067, 1726, 2191,//25
  5516, 5175, 2490,  769,  268,  141,  209,  303,  458,  875, 2273, 4174,
  6766, 7542, 5419, 3686, 2828, 1522,  709,  257,   65,   18,   29,    8,
    15,   30,   19,   34,   83,  147,  324, 1002, 1361, 1833, 2523, 3674,//26
  7319, 4002, 1093,  251,  193,  284,  568,  878, 1058, 1420, 2200, 3704,
  5133, 6007, 4894, 3567, 3106, 1918,  926,  405,   72,    4,    4,    6,
     4,   31,    3,    7,   51,  130,  424, 1324, 2216, 3224, 4255, 6717,//27
  4905, 1403,  224,   68,   80,  205,  495,  811,  922,  945, 1401, 2495,
  4199, 6009, 5594, 5039, 4551, 2869,  990,  337,   49,    5,    0,    0,
     0,    2,    0,    2,   39,  113,  547, 2674, 6560, 7703, 7839, 8289,//28
  1646,  228,   24,   16,   11,   52,   44,   93,  153,  115,  312, 1043,
  2929, 6120, 7732, 6801, 4734, 1953,  396,   36,    4,    1,    0,    0,
     0,    0,    5,    3,   12,   65, 1086,21027,57767,28567,15321, 8073,//29
   188,   23,    3,    0,    5,    3,    0,    2,   15,   23,   40,  295,
  1803, 5781, 7356, 4257, 1641,  351,   28,    4,    0,    0,    0,    0,
     6,    5,    2,    3,   14,   74, 2655,49493,86255,29323,10531, 2193,//30
     5,    4,    3,    0,    0,    0,    0,    0,    0,    6,    6,   85,
   795, 2705, 2139,  709,   97,    7,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    2,   14,   85, 1433,10936,11859, 4044,  687,   60,//31
     0,    0,    0,    0,    0,    0,    0,    0,    0,    5,    4,   39,
   187,  346,  118,   18,    3,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    1,   17,   48,  323,  729,  469,  110,    5,    2,//32
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   17,
    36,   15,    1,    4,    7,    0,    0,    0,    0,    0,    0,    0,
     4,    3,    0,    2,   12,   25,   26,   41,    8,    4,   15,    1,//33
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    6,    6,
    18,    4,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     3,    2,    0,    0,    0,    7,    3,   13,    0,    0,    2,    0,//34
     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,   12,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    4,    2,    6,    0,    0,    0,    0,//35
  };

}


void Prob_phi_2d::init( const int& size )
{
  n = size;
  data_.clear();
  data_.resize( n*n, 0.0 );
}

void Prob_phi_2d::accumulate( const ftype32 table[] )
{ for ( int i = 0; i < data_.size(); i++ ) data_[i] += table[i]; }

/*! linear interpolation onto grid */
void Prob_phi_2d::accumulate( const ftype& phi1, const ftype& phi2, ftype wgt )
{
  int   i1_0, i2_0, i1_1, i2_1;
  ftype w1_0, w2_0, w1_1, w2_1;
  w1_1 = ftype(n) * phi1 / Util::twopi();
  w2_1 = ftype(n) * phi2 / Util::twopi();
  i1_0 = Util::intf( w1_1 );
  i2_0 = Util::intf( w2_1 );
  w1_1 -= ftype( i1_0 );
  w2_1 -= ftype( i2_0 );
  w1_0 = 1.0 - w1_1;
  w2_0 = 1.0 - w2_1;
  i1_0 = Util::mod( i1_0  , n );
  i2_0 = Util::mod( i2_0  , n );
  i1_1 = Util::mod( i1_0+1, n );
  i2_1 = Util::mod( i2_0+1, n );
  data( i1_0, i2_0 ) += wgt * w1_0 * w2_0;
  data( i1_0, i2_1 ) += wgt * w1_0 * w2_1;
  data( i1_1, i2_0 ) += wgt * w1_1 * w2_0;
  data( i1_1, i2_1 ) += wgt * w1_1 * w2_1;
}

/*! normalise mean value to 1/(2pi)^2 */
void Prob_phi_2d::normalise()
{
  ftype s = 0.0;
  for ( int i = 0; i < data_.size(); i++ ) s += data_[i];
  s = ftype( data_.size() ) / ( Util::twopi() * Util::twopi() * s );
  for ( int i = 0; i < data_.size(); i++ ) data_[i] *= s;
}

/*! linear interpolation off of grid */
ftype Prob_phi_2d::probability( const ftype& phi1, const ftype& phi2 ) const
{
  int   i1_0, i2_0, i1_1, i2_1;
  ftype w1_0, w2_0, w1_1, w2_1;
  w1_1 = ftype(n) * phi1 / Util::twopi();
  w2_1 = ftype(n) * phi2 / Util::twopi();
  i1_0 = Util::intf( w1_1 );
  i2_0 = Util::intf( w2_1 );
  w1_1 -= ftype( i1_0 );
  w2_1 -= ftype( i2_0 );
  w1_0 = 1.0 - w1_1;
  w2_0 = 1.0 - w2_1;
  i1_0 = Util::mod( i1_0  , n );
  i2_0 = Util::mod( i2_0  , n );
  i1_1 = Util::mod( i1_0+1, n );
  i2_1 = Util::mod( i2_0+1, n );
  return
    w1_0 * ( w2_0 * data( i1_0, i2_0 ) + w2_1 * data( i1_0, i2_1 ) ) +
    w1_1 * ( w2_0 * data( i1_1, i2_0 ) + w2_1 * data( i1_1, i2_1 ) );
}

String Prob_phi_2d::format() const
{
  String s;
  for ( int i = 0; i < n; i++ ) {
    for ( int j = 0; j < n; j++ ) {
      if ( j % 12 == 0 ) s += "\n ";
      int k = Util::intr( data(i,j) );
      s += String( k, 5 ) + ",";
    }
    s += "//" + String( i, 2 );
  }
  return s;
}


/*! Construct a Ramachandran plot of a given type.
  \param type The residue type of the plot. Options include:
  Ramachandran::Gly, Ramachandran::Pro, Ramachandran::NonGlyPro,
  Ramachandran::NonGly, Ramachandran::All */
Ramachandran::Ramachandran( TYPE type )
{ init( type ); }

/*! Construct a Ramachandran plot of a given type.
  \param type The residue type of the plot. Options include:
  Ramachandran::Gly, Ramachandran::Pro, Ramachandran::NonGlyPro,
  Ramachandran::NonGly, Ramachandran::All */
void Ramachandran::init( TYPE type )
{
  switch (type) {
  case Gly:
    Prob_phi_2d::init( data::rama_data_size );
    Prob_phi_2d::accumulate( data::rama_gly );
    break;
  case Pro:
    Prob_phi_2d::init( data::rama_data_size );
    Prob_phi_2d::accumulate( data::rama_pro );
    break;
  case NonGlyPro:
    Prob_phi_2d::init( data::rama_data_size );
    Prob_phi_2d::accumulate( data::rama_ngp );
    break;
  case NonGly:
    Prob_phi_2d::init( data::rama_data_size );
    Prob_phi_2d::accumulate( data::rama_ngp );
    Prob_phi_2d::accumulate( data::rama_pro );
    break;
  default:
    Prob_phi_2d::init( data::rama_data_size );
    Prob_phi_2d::accumulate( data::rama_ngp );
    Prob_phi_2d::accumulate( data::rama_pro );
    Prob_phi_2d::accumulate( data::rama_gly );
    break;
  }
  Prob_phi_2d::normalise();
  set_thresholds();
}

/*! Set thresholds for favorable and allowed regions of the
  Ramachandran plot. The US spelling is used because it is the same
  length as 'allowed'. I should get out more. Sorry.
  \param prob_favored The probability threshold for the favored region.
  \param prob_allowed The probability threshold for the allowed region.
 */
void Ramachandran::set_thresholds( ftype prob_favored, ftype prob_allowed )
{ p_favored = prob_favored; p_allowed = prob_allowed; }


} // namespace clipper
