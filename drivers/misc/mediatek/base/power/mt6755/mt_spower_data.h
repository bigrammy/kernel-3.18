/*
 * Copyright (C) 2015 MediaTek Inc.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#ifndef MT_SPOWER_CPU_H
#define MT_SPOWER_CPU_H



#define VSIZE 11
#define TSIZE 26
#define MAX_TABLE_SIZE 3

/**  PLEASE MAKE SURE the following things for table interpolation:
 * 1. table order: FF,TT,SS; such that,the order is necessarily obey as following:
 *	  the power at (1150,30) should be descent absoultely.
 **/

/* "(WAT 12.6%) Leakage Power" */
#define CPU_TABLE_0							\
	{	700,	750,	800,	850,	900,	950,	1000,	1050,	1100,	1150,	1200,\
	0,	9,	12,	16,	21,	29,	38,	50,	66,	88,	117,	157,\
	5,	11,	15,	20,	26,	35,	46,	61,	80,	107,	142,	190,\
	10,	14,	19,	25,	32,	43,	57,	75,	98,	130,	173,	230,\
	15,	17,	23,	30,	40,	53,	69,	91,	120,	159,	210,	278,\
	20,	22,	28,	37,	49,	64,	84,	111,	146,	192,	254,	335,\
	25,	26,	35,	45,	59,	78,	102,	134,	176,	232,	305,	403,\
	30,	32,	42,	55,	72,	94,	124,	162,	213,	280,	367,	483,\
	35,	40,	52,	67,	88,	114,	149,	195,	256,	336,	438,	577,\
	40,	48,	63,	82,	106,	138,	180,	235,	307,	402,	523,	688,\
	45,	59,	76,	99,	128,	167,	216,	282,	367,	480,	625,	817,\
	50,	71,	92,	119,	154,	200,	260,	337,	438,	571,	745,	967,\
	55,	86,	112,	144,	186,	240,	310,	402,	522,	678,	882,	1143,\
	60,	104,	134,	173,	223,	287,	370,	479,	620,	804,	1046,	1355,\
	65,	125,	161,	206,	266,	342,	441,	568,	734,	949,	1232,	1592,\
	70,	149,	192,	246,	317,	407,	523,	673,	867,	1119,	1448,	1863,\
	75,	179,	229,	295,	378,	486,	623,	801,	1031,	1328,	1714,	2208,\
	80,	213,	273,	350,	449,	576,	737,	944,	1211,	1558,	2006,	2588,\
	85,	254,	323,	414,	532,	680,	869,	1111,	1420,	1821,	2343,	3015,\
	90,	303,	384,	490,	627,	800,	1020,	1301,	1661,	2122,	2723,	3500,\
	95,	360,	455,	578,	739,	939,	1194,	1520,	1937,	2466,	3153,	4044,\
	100,	425,	537,	681,	867,	1098,	1392,	1770,	2251,	2860,	3640,	4658,\
	105,	500,	632,	797,	1015,	1282,	1619,	2049,	2606,	3309,	4200,	5349,\
	110,	586,	740,	932,	1181,	1492,	1882,	2383,	3016,	3822,	4851,	6132,\
	115,	685,	863,	1086,	1370,	1727,	2189,	2756,	3471,	4381,	5552,	7040,\
	120,	796,	1007,	1265,	1586,	1994,	2523,	3174,	3993,	5013,	6321,	8004,\
	125,	924,	1162,	1469,	1835,	2309,	2900,	3635,	4564,	5736,	7192,	9083	}

/* "(WAT 4.2%) Leakage Power" */
#define CPU_TABLE_1							\
	{	700,	750,	800,	850,	900,	950,	1000,	1050,	1100,	1150,	1200,\
	0,	7,	9,	11,	15,	19,	25,	32,	42,	54,	71,	92,	\
	5,	8,	11,	14,	18,	23,	30,	39,	50,	66,	86,	112,	\
	10,	10,	13,	17,	22,	28,	36,	47,	61,	79,	104,	136,	\
	15,	12,	16,	20,	26,	34,	43,	57,	74,	95,	125,	164,	\
	20,	15,	19,	24,	31,	40,	52,	68,	89,	115,	151,	197,	\
	25,	17,	22,	29,	38,	49,	63,	82,	106,	138,	182,	238,	\
	30,	21,	27,	34,	45,	58,	75,	98,	127,	166,	219,	286,	\
	35,	25,	32,	41,	54,	69,	90,	117,	152,	200,	263,	345,	\
	40,	30,	38,	49,	64,	83,	108,	140,	182,	240,	317,	414,	\
	45,	36,	45,	59,	77,	99,	129,	168,	218,	288,	381,	498,	\
	50,	42,	54,	70,	91,	118,	154,	200,	261,	344,	456,	595,	\
	55,	50,	64,	83,	108,	141,	183,	238,	311,	410,	544,	712,	\
	60,	59,	76,	99,	128,	167,	217,	283,	371,	490,	648,	857,	\
	65,	70,	91,	118,	152,	198,	258,	337,	441,	582,	772,	1026,	\
	70,	82,	107,	139,	180,	234,	305,	399,	524,	691,	918,	1218,	\
	75,	98,	126,	164,	213,	277,	361,	473,	622,	821,	1087,	1449,	\
	80,	115,	149,	193,	251,	327,	427,	558,	735,	972,	1287,	1720,	\
	85,	134,	176,	227,	295,	385,	502,	659,	865,	1143,	1523,	2029,	\
	90,	158,	206,	266,	346,	452,	591,	774,	1022,	1353,	1800,	2396,	\
	95,	186,	241,	311,	406,	531,	694,	911,	1205,	1593,	2110,	2813,	\
	100,	217,	281,	364,	476,	621,	813,	1071,	1413,	1870,	2483,	3316,	\
	105,	254,	329,	428,	556,	727,	950,	1253,	1655,	2187,	2923,	3899,	\
	110,	297,	384,	499,	652,	852,	1112,	1465,	1936,	2568,	3417,	4542,	\
	115,	348,	452,	583,	761,	996,	1301,	1715,	2255,	2999,	3977,	5289,	\
	120,	405,	527,	683,	890,	1157,	1514,	1997,	2626,	3484,	4638,	6189,	\
	125,	470,	608,	794,	1035,	1349,	1765,	2316,	3054,	4072,	5412,	7264	}

/* "(WAT -8%) Leakage Power" */
#define CPU_TABLE_2							\
	{	700,	750,	800,	850,	900,	950,	1000,	1050,	1100,	1150,	1200,\
	0,	4,	5,	7,	8,	11,	13,	17,	22,	28,	36,	47,	\
	5,	5,	6,	7,	9,	12,	15,	19,	24,	31,	40,	52,	\
	10,	5,	6,	8,	10,	13,	16,	21,	27,	34,	44,	58,	\
	15,	6,	7,	9,	11,	14,	18,	23,	30,	39,	50,	66,	\
	20,	6,	8,	10,	13,	16,	20,	26,	34,	44,	57,	75,	\
	25,	7,	9,	11,	14,	18,	23,	29,	38,	50,	65,	86,	\
	30,	8,	10,	13,	16,	21,	27,	34,	44,	58,	76,	100,	\
	35,	9,	12,	15,	19,	24,	31,	40,	52,	67,	88,	116,	\
	40,	11,	14,	17,	22,	28,	36,	47,	61,	79,	104,	138,	\
	45,	13,	16,	20,	26,	33,	43,	56,	72,	95,	125,	165,	\
	50,	15,	19,	24,	31,	40,	52,	67,	87,	114,	151,	199,	\
	55,	18,	23,	29,	37,	48,	62,	81,	106,	139,	184,	243,	\
	60,	22,	28,	35,	45,	58,	76,	99,	130,	171,	225,	298,	\
	65,	27,	34,	43,	56,	72,	94,	122,	160,	211,	277,	371,	\
	70,	33,	42,	54,	69,	89,	117,	153,	200,	262,	348,	467,	\
	75,	40,	52,	67,	87,	113,	147,	191,	250,	332,	443,	595,	\
	80,	51,	65,	85,	110,	143,	186,	244,	324,	431,	575,	772,	\
	85,	65,	84,	108,	141,	185,	242,	317,	420,	558,	746,	1002,	\
	90,	84,	109,	141,	182,	238,	313,	413,	543,	726,	967,	1301,	\
	95,	109,	140,	183,	238,	313,	411,	539,	713,	954,	1272,	1711,	\
	100,	144,	186,	242,	313,	411,	540,	711,	939,	1256,	1685,	2276,	\
	105,	190,	246,	319,	417,	545,	715,	944,	1252,	1676,	2247,	3032,	\
	110,	251,	325,	424,	554,	726,	951,	1255,	1669,	2235,	3012,	4077,	\
	115,	336,	436,	566,	743,	972,	1276,	1700,	2262,	3031,	4057,	5515,	\
	120,	445,	585,	766,	1012,	1318,	1741,	2300,	3066,	4118,	5552,	7582,	\
	125,	610,	796,	1039,	1366,	1792,	2346,	3124,	4209,	5628,	7739,	10561	}

/* "(WAT 12.6%) Leakage Power" */
#define VCORE_TABLE_0							\
	{	700,	750,	800,	850,	900,	950,	1000,	1050,	1100,	1150,	1200,\
	0,	2,	2,	3,	5,	6,	9,	12,	17,	24,	34,	48,\
	5,	2,	3,	4,	6,	8,	11,	15,	20,	28,	39,	55,\
	10,	3,	4,	5,	7,	9,	12,	17,	23,	32,	45,	62,\
	15,	3,	5,	6,	8,	11,	15,	20,	27,	37,	51,	71,\
	20,	4,	6,	7,	10,	13,	18,	24,	32,	43,	59,	81,\
	25,	5,	7,	9,	12,	16,	21,	28,	37,	50,	68,	92,\
	30,	6,	8,	11,	14,	19,	24,	33,	43,	58,	78,	105,\
	35,	8,	10,	13,	17,	22,	29,	38,	50,	67,	89,	120,\
	40,	9,	12,	16,	20,	26,	34,	45,	59,	77,	102,	135,\
	45,	12,	15,	19,	25,	31,	41,	52,	68,	89,	117,	154,\
	50,	14,	18,	23,	30,	38,	48,	62,	80,	103,	135,	176,\
	55,	18,	22,	28,	36,	45,	57,	73,	93,	120,	154,	200,\
	60,	22,	27,	34,	43,	54,	68,	86,	108,	138,	177,	228,\
	65,	27,	33,	41,	51,	64,	81,	101,	126,	161,	203,	259,\
	70,	33,	40,	50,	62,	77,	95,	118,	147,	185,	233,	294,\
	75,	41,	49,	60,	74,	91,	113,	139,	171,	214,	267,	335,\
	80,	50,	60,	72,	88,	108,	132,	162,	199,	246,	306,	379,\
	85,	62,	74,	88,	106,	128,	157,	191,	232,	283,	348,	427,\
	90,	77,	91,	108,	128,	153,	184,	223,	269,	326,	397,	484,\
	95,	94,	112,	131,	154,	183,	218,	260,	312,	373,	452,	549,\
	100,	116,	137,	160,	187,	219,	258,	306,	361,	429,	516,	626,\
	105,	143,	167,	195,	225,	263,	305,	359,	422,	496,	594,	709,\
	110,	176,	203,	235,	271,	313,	364,	421,	493,	576,	682,	803,\
	115,	217,	247,	283,	327,	375,	430,	495,	574,	670,	782,	920,\
	120,	267,	302,	345,	392,	448,	511,	584,	667,	775,	899,	1048,\
	125,	328,	368,	418,	471,	536,	608,	690,	781,	888,	1027,	1190	}

/* "(WAT 4.2%) Leakage Power"  */
#define VCORE_TABLE_1							\
	{	700,	750,	800,	850,	900,	950,	1000,	1050,	1100,	1150,	1200,\
	0,	2,	3,	4,	5,	7,	9,	13,	18,	25,	35,	49,	\
	5,	2,	3,	4,	6,	8,	11,	14,	20,	27,	38,	53,	\
	10,	3,	4,	5,	7,	9,	12,	16,	22,	30,	41,	57,	\
	15,	3,	4,	6,	8,	10,	13,	18,	24,	33,	45,	62,	\
	20,	4,	5,	7,	9,	12,	15,	20,	27,	37,	50,	68,	\
	25,	5,	6,	8,	10,	13,	17,	23,	31,	41,	55,	75,	\
	30,	5,	7,	9,	12,	15,	20,	26,	35,	46,	62,	83,	\
	35,	6,	8,	11,	14,	18,	23,	30,	39,	52,	69,	93,	\
	40,	8,	10,	12,	16,	21,	27,	34,	45,	60,	78,	104,	\
	45,	9,	12,	15,	19,	24,	31,	40,	52,	68,	89,	117,	\
	50,	11,	14,	17,	22,	28,	36,	46,	60,	78,	101,	133,	\
	55,	13,	17,	21,	26,	33,	42,	54,	69,	90,	117,	151,	\
	60,	16,	20,	25,	32,	40,	50,	64,	81,	104,	134,	174,	\
	65,	20,	25,	31,	38,	47,	59,	75,	95,	121,	155,	199,	\
	70,	25,	30,	37,	46,	57,	71,	89,	113,	142,	181,	232,	\
	75,	31,	37,	46,	56,	69,	85,	106,	133,	168,	212,	269,	\
	80,	38,	46,	56,	68,	84,	103,	127,	158,	198,	249,	315,	\
	85,	48,	57,	69,	84,	102,	125,	153,	190,	235,	294,	370,	\
	90,	60,	72,	85,	103,	124,	151,	185,	227,	280,	349,	436,	\
	95,	76,	90,	106,	127,	152,	185,	224,	274,	338,	418,	519,	\
	100,	96,	113,	133,	158,	189,	228,	274,	333,	407,	499,	616,	\
	105,	123,	143,	168,	198,	236,	282,	338,	407,	490,	597,	731,	\
	110,	158,	183,	213,	249,	295,	350,	415,	495,	597,	720,	879,	\
	115,	203,	234,	271,	315,	368,	432,	512,	605,	726,	870,	1062,	\
	120,	262,	300,	346,	399,	465,	541,	634,	748,	892,	1061,	1292,	\
	125,	341,	387,	442,	513,	591,	685,	798,	929,	1101,	1293,	1565	}

/*"(WAT -8%) Leakage Power" */
#define VCORE_TABLE_2							\
	{	700,	750,	800,	850,	900,	950,	1000,	1050,	1100,	1150,	1200,\
	0,	2,	3,	4,	5,	7,	10,	14,	20,	28,	39,	55,	\
	5,	2,	3,	4,	6,	8,	11,	15,	21,	29,	40,	56,	\
	10,	3,	3,	5,	6,	8,	11,	16,	22,	30,	41,	58,	\
	15,	3,	4,	5,	7,	9,	12,	17,	23,	31,	43,	60,	\
	20,	3,	4,	5,	7,	10,	13,	18,	24,	33,	45,	62,	\
	25,	3,	5,	6,	8,	11,	14,	19,	26,	35,	48,	66,	\
	30,	4,	5,	7,	9,	12,	16,	21,	28,	38,	51,	70,	\
	35,	4,	6,	7,	10,	13,	17,	23,	30,	41,	55,	74,	\
	40,	5,	7,	8,	11,	14,	19,	25,	33,	44,	59,	80,	\
	45,	6,	7,	10,	12,	16,	21,	28,	37,	48,	64,	86,	\
	50,	7,	9,	11,	14,	18,	24,	31,	41,	53,	70,	93,	\
	55,	8,	10,	13,	16,	21,	27,	35,	45,	59,	77,	102,	\
	60,	9,	12,	15,	19,	24,	30,	39,	50,	65,	86,	112,	\
	65,	11,	14,	17,	22,	27,	35,	44,	57,	73,	96,	125,	\
	70,	13,	16,	20,	25,	32,	40,	51,	65,	83,	107,	139,	\
	75,	15,	19,	24,	30,	37,	47,	59,	74,	94,	121,	157,	\
	80,	19,	23,	28,	35,	43,	54,	68,	85,	108,	137,	176,	\
	85,	22,	27,	34,	41,	51,	63,	79,	99,	124,	156,	200,	\
	90,	27,	33,	41,	49,	61,	75,	93,	115,	143,	180,	227,	\
	95,	34,	41,	49,	60,	73,	89,	109,	136,	167,	208,	262,	\
	100,	42,	50,	60,	72,	88,	107,	131,	161,	197,	244,	305,	\
	105,	52,	62,	74,	88,	107,	129,	157,	191,	234,	288,	356,	\
	110,	65,	77,	91,	109,	130,	156,	189,	228,	278,	340,	418,	\
	115,	82,	96,	114,	135,	160,	191,	229,	276,	334,	405,	497,	\
	120,	104,	122,	143,	168,	198,	235,	281,	335,	404,	486,	592,	\
	125,	133,	155,	180,	211,	247,	292,	346,	410,	490,	587,	716	}

/* "(WAT 12.6%) Leakage Power"	 */
#define GPU_TABLE_0							\
	{	700,	750,	800,	850,	900,	950,	1000,	1050,	1100,	1150,	1200,\
	0,	1,	1,	2,	2,	3,	4,	5,	7,	10,	14,	19,\
	5,	1,	1,	2,	2,	3,	4,	6,	8,	11,	15,	21,\
	10,	1,	2,	2,	3,	4,	5,	7,	9,	12,	16,	22,\
	15,	1,	2,	2,	3,	4,	6,	8,	10,	13,	18,	24,\
	20,	2,	2,	3,	4,	5,	7,	9,	12,	15,	20,	27,\
	25,	2,	3,	3,	4,	6,	8,	10,	13,	17,	23,	30,\
	30,	2,	3,	4,	5,	7,	9,	12,	15,	20,	26,	34,\
	35,	3,	4,	5,	6,	8,	11,	14,	18,	23,	30,	38,\
	40,	4,	5,	6,	8,	10,	13,	16,	20,	26,	34,	44,\
	45,	5,	6,	7,	9,	12,	15,	19,	24,	31,	39,	50,\
	50,	6,	7,	9,	11,	14,	18,	23,	29,	36,	46,	58,\
	55,	7,	9,	11,	14,	17,	22,	27,	34,	43,	53,	67,\
	60,	9,	11,	14,	17,	21,	26,	32,	40,	50,	63,	78,\
	65,	11,	14,	17,	21,	25,	32,	39,	47,	59,	73,	91,\
	70,	14,	17,	21,	26,	32,	38,	47,	58,	71,	87,	107,\
	75,	18,	22,	27,	32,	39,	47,	56,	69,	85,	104,	127,\
	80,	23,	28,	34,	40,	48,	58,	70,	84,	102,	124,	152,\
	85,	30,	36,	43,	51,	60,	72,	86,	103,	124,	149,	182,\
	90,	39,	46,	55,	64,	76,	91,	108,	129,	152,	183,	219,\
	95,	51,	60,	71,	83,	98,	114,	135,	160,	190,	226,	269,\
	100,	67,	78,	93,	109,	128,	147,	172,	202,	239,	282,	332,\
	105,	90,	104,	122,	143,	165,	191,	221,	259,	302,	354,	415,\
	110,	121,	140,	162,	186,	215,	248,	281,	329,	383,	447,	517,\
	115,	165,	191,	216,	245,	279,	318,	362,	417,	477,	552,	639,\
	120,	224,	256,	291,	326,	369,	415,	473,	534,	604,	692,	793,\
	125,	308,	350,	395,	443,	495,	550,	621,	689,	777,	883,	995	}

/* "(WAT 4.2%) Leakage Power"  */
#define GPU_TABLE_1							\
	{	700,	750,	800,	850,	900,	950,	1000,	1050,	1100,	1150,	1200,\
	0,	1,	1,	1,	2,	3,	3,	4,	6,	8,	11,	15,	\
	5,	1,	1,	2,	2,	3,	4,	5,	7,	9,	12,	16,	\
	10,	1,	1,	2,	2,	3,	4,	6,	7,	10,	13,	18,	\
	15,	1,	2,	2,	3,	4,	5,	6,	8,	11,	15,	20,	\
	20,	1,	2,	2,	3,	4,	5,	7,	9,	12,	16,	22,	\
	25,	2,	2,	3,	4,	5,	6,	8,	10,	14,	18,	24,	\
	30,	2,	2,	3,	4,	5,	7,	9,	12,	15,	20,	27,	\
	35,	2,	3,	4,	5,	6,	8,	10,	13,	17,	23,	30,	\
	40,	3,	4,	4,	6,	7,	9,	12,	15,	20,	26,	34,	\
	45,	3,	4,	5,	7,	8,	11,	14,	18,	23,	29,	38,	\
	50,	4,	5,	6,	8,	10,	13,	16,	20,	26,	33,	43,	\
	55,	5,	6,	8,	10,	12,	15,	19,	24,	30,	39,	49,	\
	60,	6,	8,	9,	12,	15,	18,	23,	28,	36,	45,	57,	\
	65,	8,	10,	12,	14,	18,	22,	27,	34,	42,	52,	65,	\
	70,	10,	12,	15,	18,	22,	27,	33,	40,	50,	62,	77,	\
	75,	13,	15,	18,	22,	27,	32,	40,	49,	60,	74,	92,	\
	80,	16,	19,	23,	28,	33,	40,	49,	59,	72,	89,	110,	\
	85,	21,	25,	29,	35,	42,	50,	60,	73,	88,	108,	132,	\
	90,	27,	32,	38,	44,	53,	63,	75,	90,	108,	131,	160,	\
	95,	35,	41,	49,	57,	67,	79,	93,	110,	132,	160,	194,	\
	100,	47,	54,	64,	74,	86,	100,	118,	139,	164,	197,	238,	\
	105,	63,	73,	83,	95,	110,	127,	149,	174,	206,	244,	290,	\
	110,	86,	96,	110,	124,	143,	164,	191,	220,	262,	309,	366,	\
	115,	114,	128,	145,	163,	186,	215,	246,	285,	335,	392,	461,	\
	120,	152,	172,	192,	218,	248,	281,	323,	373,	430,	503,	586,	\
	125,	207,	233,	260,	295,	330,	368,	423,	488,	560,	651,	750	}

/* "(WAT -8%) Leakage Power" */
#define GPU_TABLE_2							\
	{	700,	750,	800,	850,	900,	950,	1000,	1050,	1100,	1150,	1200,\
	0,	1,	1,	2,	2,	3,	4,	6,	8,	10,	14,	20,	\
	5,	1,	1,	2,	2,	3,	4,	6,	8,	11,	15,	20,	\
	10,	1,	1,	2,	3,	3,	5,	6,	8,	11,	15,	21,	\
	15,	1,	2,	2,	3,	4,	5,	7,	9,	12,	16,	21,	\
	20,	1,	2,	2,	3,	4,	5,	7,	9,	13,	17,	22,	\
	25,	1,	2,	3,	3,	4,	6,	8,	10,	13,	18,	23,	\
	30,	2,	2,	3,	4,	5,	6,	8,	11,	14,	19,	25,	\
	35,	2,	2,	3,	4,	5,	7,	9,	12,	16,	20,	26,	\
	40,	2,	3,	4,	5,	6,	8,	10,	13,	17,	22,	28,	\
	45,	3,	3,	4,	5,	7,	9,	11,	14,	18,	24,	30,	\
	50,	3,	4,	5,	6,	8,	10,	13,	16,	20,	26,	33,	\
	55,	3,	4,	6,	7,	9,	11,	14,	18,	23,	29,	37,	\
	60,	4,	5,	6,	8,	10,	13,	16,	20,	26,	32,	41,	\
	65,	5,	6,	8,	9,	12,	15,	18,	23,	29,	36,	46,	\
	70,	6,	7,	9,	11,	14,	17,	21,	26,	33,	41,	52,	\
	75,	7,	9,	11,	13,	16,	20,	25,	31,	38,	47,	59,	\
	80,	9,	10,	13,	16,	19,	24,	29,	36,	44,	54,	67,	\
	85,	10,	13,	15,	19,	23,	28,	34,	42,	51,	63,	77,	\
	90,	13,	15,	19,	23,	28,	34,	41,	49,	60,	74,	90,	\
	95,	16,	19,	23,	28,	33,	40,	48,	59,	72,	87,	105,	\
	100,	20,	24,	28,	34,	41,	49,	58,	71,	85,	103,	124,	\
	105,	25,	30,	36,	42,	51,	60,	72,	85,	102,	122,	146,	\
	110,	32,	37,	44,	53,	64,	74,	87,	104,	124,	147,	176,	\
	115,	40,	47,	56,	67,	79,	93,	108,	127,	151,	179,	213,	\
	120,	52,	60,	72,	85,	99,	115,	134,	158,	187,	218,	258,	\
	125,	69,	79,	92,	108,	127,	144,	168,	197,	231,	270,	315	}

/* "(WAT 12.6%) Leakage Power"	 */
#define VMD1_TABLE_0							\
	{	700,	750,	800,	850,	900,	950,	1000,	1050,	1100,	1150,	1200,\
	0,	1,	2,	2,	3,	5,	6,	8,	11,	15,	21,	29,\
	5,	2,	2,	3,	4,	5,	7,	10,	13,	18,	25,	33,\
	10,	2,	3,	4,	5,	7,	9,	12,	16,	21,	28,	38,\
	15,	2,	3,	4,	6,	8,	10,	14,	18,	24,	33,	44,\
	20,	3,	4,	5,	7,	9,	12,	16,	22,	29,	38,	50,\
	25,	4,	5,	6,	8,	11,	15,	19,	25,	33,	44,	58,\
	30,	5,	6,	8,	10,	13,	17,	23,	29,	39,	51,	67,\
	35,	6,	7,	9,	12,	16,	20,	27,	34,	45,	58,	76,\
	40,	7,	9,	11,	15,	19,	24,	31,	40,	52,	67,	88,\
	45,	8,	11,	14,	18,	22,	29,	37,	47,	60,	78,	100,\
	50,	10,	13,	17,	21,	27,	34,	43,	55,	70,	90,	115,\
	55,	13,	16,	20,	25,	32,	40,	51,	64,	81,	103,	131,\
	60,	15,	19,	24,	30,	38,	48,	60,	75,	94,	119,	150,\
	65,	19,	23,	29,	36,	45,	56,	70,	87,	109,	137,	172,\
	70,	23,	28,	35,	43,	54,	66,	82,	102,	126,	157,	196,\
	75,	28,	34,	42,	52,	64,	78,	96,	118,	146,	180,	224,\
	80,	34,	42,	51,	62,	76,	92,	112,	137,	168,	207,	255,\
	85,	42,	50,	61,	74,	90,	108,	131,	160,	194,	237,	290,\
	90,	51,	61,	73,	89,	106,	128,	154,	186,	225,	272,	331,\
	95,	62,	74,	88,	105,	126,	151,	181,	216,	260,	312,	376,\
	100,	75,	89,	106,	125,	149,	178,	211,	252,	300,	359,	428,\
	105,	92,	108,	127,	149,	175,	207,	246,	292,	346,	410,	487,\
	110,	112,	131,	152,	178,	208,	243,	285,	335,	396,	468,	553,\
	115,	136,	159,	183,	212,	245,	285,	332,	388,	454,	533,	626,\
	120,	166,	191,	220,	253,	292,	335,	387,	449,	521,	606,	706,\
	125,	202,	231,	264,	302,	345,	394,	452,	520,	600,	693,	802	}

/* "(WAT 4.2%) Leakage Power"  */
#define VMD1_TABLE_1							\
	{	700,	750,	800,	850,	900,	950,	1000,	1050,	1100,	1150,	1200,\
	0,	1,	1,	2,	3,	3,	5,	6,	9,	12,	16,	22,	\
	5,	1,	2,	2,	3,	4,	5,	7,	10,	13,	18,	25,	\
	10,	1,	2,	3,	4,	5,	6,	9,	11,	15,	21,	28,	\
	15,	2,	2,	3,	4,	6,	7,	10,	13,	18,	23,	32,	\
	20,	2,	3,	4,	5,	7,	9,	11,	15,	20,	27,	36,	\
	25,	3,	3,	4,	6,	8,	10,	13,	18,	23,	31,	41,	\
	30,	3,	4,	5,	7,	9,	12,	16,	20,	27,	35,	46,	\
	35,	4,	5,	6,	8,	11,	14,	18,	24,	31,	40,	52,	\
	40,	5,	6,	8,	10,	13,	16,	21,	28,	36,	46,	60,	\
	45,	6,	7,	9,	12,	15,	19,	25,	32,	41,	53,	68,	\
	50,	7,	9,	11,	14,	18,	23,	29,	37,	48,	61,	78,	\
	55,	8,	11,	13,	17,	22,	27,	35,	44,	55,	71,	90,	\
	60,	10,	13,	16,	20,	26,	32,	41,	51,	65,	82,	103,	\
	65,	13,	16,	20,	25,	31,	38,	48,	60,	76,	95,	119,	\
	70,	16,	19,	24,	30,	37,	46,	57,	71,	88,	110,	137,	\
	75,	19,	24,	29,	36,	44,	55,	68,	84,	103,	128,	158,	\
	80,	24,	29,	36,	44,	53,	65,	80,	98,	121,	149,	184,	\
	85,	30,	36,	44,	53,	64,	78,	95,	116,	142,	174,	213,	\
	90,	37,	44,	53,	64,	78,	94,	113,	137,	167,	203,	249,	\
	95,	46,	55,	66,	78,	94,	113,	135,	163,	196,	238,	288,	\
	100,	57,	68,	81,	96,	114,	136,	162,	194,	232,	279,	336,	\
	105,	71,	84,	99,	117,	138,	163,	194,	231,	275,	328,	392,	\
	110,	89,	104,	122,	143,	168,	197,	233,	275,	325,	386,	458,	\
	115,	111,	129,	150,	175,	204,	239,	280,	328,	386,	454,	537,	\
	120,	139,	160,	185,	214,	248,	288,	334,	390,	456,	534,	629,	\
	125,	173,	199,	228,	262,	302,	349,	404,	468,	543,	633,	739	}

/* "(WAT -8%) Leakage Power" */
#define VMD1_TABLE_2							\
	{	700,	750,	800,	850,	900,	950,	1000,	1050,	1100,	1150,	1200,\
	0,	1,	1,	2,	3,	4,	5,	7,	9,	13,	17,	24,	\
	5,	1,	2,	2,	3,	4,	5,	7,	10,	13,	18,	25,	\
	10,	1,	2,	2,	3,	4,	6,	8,	10,	14,	19,	26,	\
	15,	1,	2,	3,	3,	5,	6,	8,	11,	15,	20,	27,	\
	20,	2,	2,	3,	4,	5,	7,	9,	12,	16,	22,	29,	\
	25,	2,	2,	3,	4,	6,	7,	10,	13,	17,	23,	31,	\
	30,	2,	3,	4,	5,	6,	8,	11,	14,	19,	25,	33,	\
	35,	2,	3,	4,	5,	7,	9,	12,	16,	21,	27,	36,	\
	40,	3,	4,	5,	6,	8,	10,	13,	17,	23,	30,	39,	\
	45,	3,	4,	5,	7,	9,	12,	15,	19,	25,	33,	43,	\
	50,	4,	5,	6,	8,	10,	13,	17,	22,	28,	36,	47,	\
	55,	5,	6,	7,	9,	12,	15,	19,	24,	31,	40,	52,	\
	60,	5,	7,	8,	11,	14,	17,	22,	28,	35,	45,	58,	\
	65,	6,	8,	10,	13,	16,	20,	25,	32,	40,	51,	65,	\
	70,	8,	9,	12,	15,	18,	23,	29,	36,	46,	58,	73,	\
	75,	9,	11,	14,	17,	22,	27,	34,	42,	52,	66,	83,	\
	80,	11,	14,	17,	21,	26,	32,	39,	49,	61,	76,	95,	\
	85,	14,	17,	20,	25,	31,	38,	46,	57,	71,	88,	109,	\
	90,	17,	20,	25,	30,	37,	45,	55,	67,	83,	102,	126,	\
	95,	20,	25,	30,	36,	44,	53,	65,	80,	97,	119,	146,	\
	100,	25,	30,	37,	44,	53,	65,	78,	95,	115,	140,	171,	\
	105,	32,	38,	45,	55,	65,	79,	95,	114,	137,	165,	201,	\
	110,	40,	48,	56,	67,	80,	96,	115,	137,	165,	198,	239,	\
	115,	51,	60,	71,	84,	99,	118,	140,	167,	199,	237,	285,	\
	120,	65,	77,	90,	105,	124,	146,	172,	205,	242,	288,	342,	\
	125,	84,	97,	114,	133,	155,	182,	214,	251,	296,	351,	413	}

/* "(WAT 12.6%) Leakage Power"	 */
#define MODEM_TABLE_0							\
	{	700,	750,	800,	850,	900,	950,	1000,	1050,	1100,	1150,	1200,\
	0,	1,	2,	3,	4,	5,	6,	9,	12,	16,	21,	28,\
	5,	2,	2,	3,	4,	6,	8,	10,	14,	18,	24,	32,\
	10,	2,	3,	4,	5,	7,	9,	12,	16,	21,	28,	37,\
	15,	3,	4,	5,	6,	8,	11,	14,	19,	25,	32,	42,\
	20,	3,	4,	6,	7,	10,	13,	17,	22,	28,	37,	48,\
	25,	4,	5,	7,	9,	12,	15,	20,	25,	33,	42,	55,\
	30,	5,	6,	8,	11,	14,	18,	23,	30,	38,	49,	63,\
	35,	6,	8,	10,	13,	17,	21,	27,	35,	45,	57,	73,\
	40,	7,	9,	12,	15,	20,	25,	32,	41,	52,	66,	84,\
	45,	9,	11,	15,	19,	24,	30,	38,	48,	61,	77,	96,\
	50,	11,	14,	18,	22,	28,	36,	45,	56,	71,	89,	111,\
	55,	13,	17,	22,	27,	34,	43,	53,	66,	83,	103,	128,\
	60,	17,	21,	26,	33,	41,	51,	63,	78,	97,	120,	148,\
	65,	21,	26,	32,	40,	49,	61,	75,	92,	113,	139,	170,\
	70,	25,	32,	39,	48,	59,	72,	89,	109,	133,	162,	197,\
	75,	31,	39,	48,	59,	71,	87,	105,	128,	155,	188,	229,\
	80,	39,	48,	58,	71,	86,	104,	125,	151,	182,	220,	265,\
	85,	48,	58,	71,	86,	104,	125,	150,	179,	215,	256,	306,\
	90,	60,	72,	87,	104,	125,	150,	179,	212,	252,	300,	355,\
	95,	74,	89,	106,	127,	151,	180,	214,	252,	297,	350,	412,\
	100,	93,	110,	131,	155,	183,	216,	255,	299,	350,	410,	479,\
	105,	116,	137,	161,	189,	222,	260,	304,	355,	413,	480,	557,\
	110,	144,	169,	199,	231,	269,	313,	364,	422,	487,	563,	649,\
	115,	181,	210,	244,	284,	327,	377,	436,	502,	575,	659,	756,\
	120,	226,	262,	301,	347,	398,	457,	522,	596,	681,	775,	881,\
	125,	281,	324,	372,	425,	483,	550,	625,	709,	804,	911,	1031	}

/* "(WAT 4.2%) Leakage Power"  */
#define MODEM_TABLE_1							\
	{	700,	750,	800,	850,	900,	950,	1000,	1050,	1100,	1150,	1200,\
	0,	1,	1,	2,	3,	4,	5,	7,	9,	12,	16,	22,	\
	5,	1,	2,	2,	3,	4,	6,	7,	10,	14,	18,	24,	\
	10,	1,	2,	3,	4,	5,	6,	9,	11,	15,	20,	27,	\
	15,	2,	2,	3,	4,	6,	7,	10,	13,	17,	23,	30,	\
	20,	2,	3,	4,	5,	7,	9,	11,	15,	20,	26,	34,	\
	25,	3,	3,	4,	6,	8,	10,	13,	17,	22,	29,	38,	\
	30,	3,	4,	5,	7,	9,	12,	15,	20,	26,	33,	43,	\
	35,	4,	5,	6,	8,	11,	14,	18,	23,	30,	38,	49,	\
	40,	5,	6,	8,	10,	13,	16,	21,	27,	34,	44,	55,	\
	45,	6,	7,	9,	12,	15,	19,	25,	31,	40,	50,	63,	\
	50,	7,	9,	11,	14,	18,	23,	29,	37,	46,	58,	73,	\
	55,	9,	11,	14,	17,	22,	28,	35,	43,	54,	68,	84,	\
	60,	11,	13,	17,	21,	27,	33,	41,	51,	64,	79,	98,	\
	65,	13,	17,	21,	26,	32,	40,	49,	61,	75,	93,	114,	\
	70,	17,	21,	26,	32,	40,	49,	60,	73,	89,	109,	133,	\
	75,	21,	26,	32,	40,	49,	59,	72,	88,	106,	130,	157,	\
	80,	27,	33,	40,	50,	60,	73,	87,	106,	128,	154,	185,	\
	85,	34,	42,	51,	62,	74,	89,	107,	129,	154,	184,	220,	\
	90,	44,	53,	64,	77,	92,	110,	131,	156,	186,	221,	262,	\
	95,	56,	68,	81,	96,	114,	135,	161,	191,	225,	266,	314,	\
	100,	72,	86,	102,	121,	142,	168,	198,	233,	273,	320,	376,	\
	105,	94,	110,	129,	152,	178,	208,	244,	285,	333,	388,	452,	\
	110,	122,	142,	165,	192,	223,	260,	302,	350,	406,	471,	546,	\
	115,	158,	183,	212,	245,	282,	325,	376,	432,	497,	573,	660,	\
	120,	207,	237,	272,	312,	358,	411,	470,	537,	614,	702,	802,	\
	125,	271,	310,	352,	401,	456,	519,	590,	669,	759,	862,	980	}

/* "(WAT -8%) Leakage Power" */
#define MODEM_TABLE_2							\
	{	700,	750,	800,	850,	900,	950,	1000,	1050,	1100,	1150,	1200,\
	0,	1,	2,	2,	3,	4,	5,	7,	10,	13,	18,	24,	\
	5,	1,	2,	2,	3,	4,	6,	8,	10,	14,	19,	25,	\
	10,	1,	2,	3,	3,	5,	6,	8,	11,	14,	19,	26,	\
	15,	2,	2,	3,	4,	5,	7,	9,	12,	15,	20,	27,	\
	20,	2,	2,	3,	4,	5,	7,	9,	12,	16,	22,	29,	\
	25,	2,	3,	3,	4,	6,	8,	10,	13,	18,	23,	30,	\
	30,	2,	3,	4,	5,	7,	9,	11,	15,	19,	25,	33,	\
	35,	3,	3,	4,	6,	7,	10,	12,	16,	21,	27,	35,	\
	40,	3,	4,	5,	6,	8,	11,	14,	18,	23,	29,	38,	\
	45,	3,	4,	6,	7,	9,	12,	15,	20,	25,	32,	41,	\
	50,	4,	5,	7,	8,	11,	14,	18,	22,	28,	36,	46,	\
	55,	5,	6,	8,	10,	12,	16,	20,	25,	32,	40,	51,	\
	60,	6,	7,	9,	12,	15,	18,	23,	29,	36,	45,	57,	\
	65,	7,	9,	11,	14,	17,	21,	27,	33,	41,	52,	64,	\
	70,	8,	10,	13,	16,	20,	25,	31,	38,	48,	59,	73,	\
	75,	10,	13,	16,	19,	24,	30,	36,	45,	55,	68,	84,	\
	80,	12,	15,	19,	23,	29,	35,	43,	53,	65,	79,	97,	\
	85,	15,	19,	23,	28,	35,	42,	52,	63,	77,	93,	114,	\
	90,	19,	24,	29,	35,	42,	51,	62,	75,	91,	110,	133,	\
	95,	24,	29,	36,	43,	52,	63,	76,	91,	109,	132,	158,	\
	100,	31,	37,	45,	54,	65,	77,	93,	110,	132,	158,	188,	\
	105,	39,	47,	57,	67,	81,	96,	114,	136,	161,	191,	227,	\
	110,	51,	61,	72,	86,	101,	120,	142,	168,	198,	234,	276,	\
	115,	67,	78,	93,	109,	129,	151,	177,	208,	245,	288,	337,	\
	120,	87,	102,	120,	141,	165,	192,	224,	261,	305,	355,	416,	\
	125,	115,	135,	157,	182,	211,	246,	286,	332,	384,	445,	516	}

/* "(WAT 12.6%) Leakage Power"	 */
#define VMODEM_SRAM_TABLE_0							\
	{	700,	750,	800,	850,	900,	950,	1000,	1050,	1100,	1150,	1200,\
	0,	2,	2,	3,	5,	7,	9,	12,	17,	23,	32,	44,\
	5,	2,	3,	4,	5,	7,	10,	13,	18,	25,	34,	46,\
	10,	2,	3,	4,	6,	8,	11,	14,	19,	26,	35,	48,\
	15,	3,	4,	5,	6,	9,	12,	16,	21,	28,	38,	51,\
	20,	3,	4,	5,	7,	10,	13,	17,	23,	31,	41,	55,\
	25,	3,	5,	6,	8,	11,	15,	19,	26,	34,	45,	59,\
	30,	4,	5,	7,	9,	12,	16,	22,	28,	37,	49,	64,\
	35,	5,	6,	8,	11,	14,	18,	24,	32,	41,	54,	70,\
	40,	5,	7,	9,	12,	16,	21,	27,	36,	46,	60,	77,\
	45,	6,	8,	11,	14,	19,	24,	31,	40,	52,	67,	86,\
	50,	8,	10,	13,	17,	22,	28,	36,	46,	59,	75,	96,\
	55,	9,	12,	15,	20,	25,	32,	41,	52,	67,	85,	108,\
	60,	11,	14,	18,	23,	29,	37,	48,	60,	76,	97,	122,\
	65,	13,	17,	22,	28,	35,	44,	56,	70,	88,	110,	138,\
	70,	16,	21,	26,	33,	42,	52,	65,	82,	102,	127,	158,\
	75,	20,	26,	32,	40,	50,	62,	78,	96,	119,	148,	182,\
	80,	25,	31,	39,	49,	61,	75,	92,	114,	140,	172,	211,\
	85,	31,	39,	48,	59,	73,	90,	110,	136,	166,	203,	247,\
	90,	39,	49,	59,	73,	88,	108,	132,	161,	197,	240,	290,\
	95,	49,	61,	74,	90,	109,	132,	162,	196,	236,	285,	343,\
	100,	62,	76,	93,	113,	136,	164,	197,	237,	284,	341,	408,\
	105,	79,	97,	117,	141,	170,	203,	243,	290,	346,	412,	489,\
	110,	102,	124,	149,	179,	214,	254,	302,	357,	422,	498,	587,\
	115,	132,	159,	189,	227,	269,	317,	374,	438,	515,	605,	710,\
	120,	171,	203,	242,	286,	336,	397,	466,	546,	637,	743,	868,\
	125,	222,	263,	308,	361,	424,	497,	578,	676,	788,	916,	1061	}

/* "(WAT 4.2%) Leakage Power"  */
#define VMODEM_SRAM_TABLE_1							\
	{	700,	750,	800,	850,	900,	950,	1000,	1050,	1100,	1150,	1200,\
	0,	4,	5,	6,	8,	10,	13,	17,	22,	28,	36,	46,	\
	5,	4,	5,	7,	9,	11,	14,	18,	23,	29,	37,	49,	\
	10,	5,	6,	7,	9,	12,	15,	19,	24,	31,	40,	52,	\
	15,	5,	6,	8,	10,	12,	16,	20,	26,	33,	42,	55,	\
	20,	5,	7,	8,	11,	13,	17,	21,	27,	35,	45,	59,	\
	25,	6,	7,	9,	12,	14,	18,	23,	30,	38,	49,	63,	\
	30,	6,	8,	10,	13,	16,	20,	25,	32,	42,	53,	69,	\
	35,	7,	9,	11,	14,	17,	22,	28,	35,	45,	58,	75,	\
	40,	8,	10,	12,	15,	19,	24,	31,	39,	50,	64,	83,	\
	45,	9,	11,	13,	17,	21,	27,	34,	44,	56,	72,	92,	\
	50,	10,	12,	15,	19,	24,	30,	38,	49,	62,	80,	103,	\
	55,	11,	14,	17,	22,	27,	34,	43,	55,	70,	90,	116,	\
	60,	13,	16,	20,	25,	31,	39,	49,	63,	80,	102,	132,	\
	65,	15,	18,	23,	28,	36,	45,	57,	72,	92,	118,	151,	\
	70,	17,	21,	26,	33,	41,	52,	66,	84,	106,	135,	174,	\
	75,	20,	25,	31,	39,	48,	61,	77,	97,	123,	156,	201,	\
	80,	23,	29,	36,	45,	56,	71,	90,	113,	144,	184,	235,	\
	85,	28,	34,	43,	53,	66,	83,	105,	133,	169,	216,	277,	\
	90,	33,	41,	51,	63,	79,	99,	124,	158,	201,	257,	328,	\
	95,	39,	49,	61,	76,	95,	118,	149,	188,	239,	305,	391,	\
	100,	47,	59,	73,	91,	113,	142,	178,	225,	286,	365,	466,	\
	105,	57,	71,	88,	110,	137,	171,	214,	271,	344,	440,	564,	\
	110,	70,	87,	108,	134,	166,	208,	261,	330,	419,	536,	687,	\
	115,	86,	106,	132,	164,	205,	256,	320,	403,	511,	653,	837,	\
	120,	107,	131,	162,	202,	251,	315,	393,	495,	627,	801,	1035,	\
	125,	133,	163,	202,	249,	310,	388,	486,	610,	774,	988,	1272	}

/* "(WAT -8%) Leakage Power" */
#define VMODEM_SRAM_TABLE_2							\
	{	700,	750,	800,	850,	900,	950,	1000,	1050,	1100,	1150,	1200,\
	0,	2,	3,	4,	5,	7,	9,	12,	16,	22,	29,	39,	\
	5,	3,	3,	4,	6,	7,	10,	13,	17,	22,	30,	40,	\
	10,	3,	4,	5,	6,	8,	10,	13,	17,	23,	31,	42,	\
	15,	3,	4,	5,	6,	8,	11,	14,	18,	24,	32,	43,	\
	20,	3,	4,	5,	7,	9,	11,	15,	19,	25,	34,	45,	\
	25,	3,	4,	5,	7,	9,	12,	15,	20,	27,	35,	47,	\
	30,	4,	5,	6,	8,	10,	13,	16,	22,	28,	37,	49,	\
	35,	4,	5,	6,	8,	10,	14,	18,	23,	30,	40,	52,	\
	40,	4,	5,	7,	9,	11,	15,	19,	25,	32,	42,	56,	\
	45,	5,	6,	8,	10,	12,	16,	21,	27,	35,	46,	60,	\
	50,	5,	7,	8,	11,	14,	18,	23,	29,	38,	50,	65,	\
	55,	6,	7,	9,	12,	15,	19,	25,	32,	42,	54,	71,	\
	60,	7,	8,	10,	13,	17,	22,	28,	36,	46,	60,	78,	\
	65,	8,	9,	12,	15,	19,	24,	31,	39,	51,	66,	85,	\
	70,	9,	11,	13,	17,	21,	27,	34,	44,	57,	73,	95,	\
	75,	10,	12,	15,	19,	24,	31,	39,	50,	64,	82,	106,	\
	80,	11,	14,	17,	22,	28,	35,	44,	56,	72,	92,	119,	\
	85,	13,	16,	20,	25,	32,	40,	50,	64,	81,	104,	135,	\
	90,	15,	19,	23,	29,	36,	46,	58,	73,	92,	118,	152,	\
	95,	18,	22,	27,	34,	42,	53,	67,	85,	106,	136,	175,	\
	100,	21,	26,	32,	39,	49,	61,	77,	97,	123,	157,	202,	\
	105,	25,	30,	37,	46,	57,	72,	90,	112,	142,	181,	232,	\
	110,	29,	36,	44,	54,	67,	84,	104,	130,	165,	210,	268,	\
	115,	35,	42,	52,	64,	79,	98,	121,	153,	193,	244,	311,	\
	120,	41,	50,	61,	76,	93,	115,	143,	179,	224,	284,	361,	\
	125,	49,	60,	74,	90,	111,	137,	168,	211,	264,	332,	423	}

typedef struct spower_raw_s {
	int vsize;
	int tsize;
	int table_size;
	int *table[];
} spower_raw_t;


/** table order: ff,tt,ss **/

int cpu_leakage_data[][VSIZE*TSIZE+VSIZE+TSIZE] = {
		CPU_TABLE_0,
		CPU_TABLE_1,
		CPU_TABLE_2,
};

int vcore_leakage_data[][VSIZE*TSIZE+VSIZE+TSIZE] = {
		VCORE_TABLE_0,
		VCORE_TABLE_1,
		VCORE_TABLE_2,
};

int gpu_leakage_data[][VSIZE*TSIZE+VSIZE+TSIZE] = {
		GPU_TABLE_0,
		GPU_TABLE_1,
		GPU_TABLE_2,
};

int vmd1_leakage_data[][VSIZE*TSIZE+VSIZE+TSIZE] = {
		VMD1_TABLE_0,
		VMD1_TABLE_1,
		VMD1_TABLE_2,
};

int modem_leakage_data[][VSIZE*TSIZE+VSIZE+TSIZE] = {
		MODEM_TABLE_0,
		MODEM_TABLE_1,
		MODEM_TABLE_2,
};

int vmodem_sram_leakage_data[][VSIZE*TSIZE+VSIZE+TSIZE] = {
		VMODEM_SRAM_TABLE_0,
		VMODEM_SRAM_TABLE_1,
		VMODEM_SRAM_TABLE_2,
};

spower_raw_t cpu_spower_raw = {
	.vsize = VSIZE,
	.tsize = TSIZE,
	.table_size = MAX_TABLE_SIZE,
	.table = { (int *)&cpu_leakage_data[0], (int *)&cpu_leakage_data[1], (int *)&cpu_leakage_data[2] },
};

spower_raw_t vcore_spower_raw = {
	.vsize = VSIZE,
	.tsize = TSIZE,
	.table_size = MAX_TABLE_SIZE,
	.table = { (int *)&vcore_leakage_data[0], (int *)&vcore_leakage_data[1], (int *)&vcore_leakage_data[2] },
};

spower_raw_t gpu_spower_raw = {
	.vsize = VSIZE,
	.tsize = TSIZE,
	.table_size = MAX_TABLE_SIZE,
	.table = { (int *)&gpu_leakage_data[0], (int *)&gpu_leakage_data[1], (int *)&gpu_leakage_data[2] },
};

spower_raw_t vmd1_spower_raw = {
	.vsize = VSIZE,
	.tsize = TSIZE,
	.table_size = MAX_TABLE_SIZE,
	.table = { (int *)&vmd1_leakage_data[0], (int *)&vmd1_leakage_data[1], (int *)&vmd1_leakage_data[2] },
};

spower_raw_t modem_spower_raw = {
	.vsize = VSIZE,
	.tsize = TSIZE,
	.table_size = MAX_TABLE_SIZE,
	.table = { (int *)&modem_leakage_data[0], (int *)&modem_leakage_data[1], (int *)&modem_leakage_data[2] },
};

spower_raw_t vmodem_sram_spower_raw = {
	.vsize = VSIZE,
	.tsize = TSIZE,
	.table_size = MAX_TABLE_SIZE,
	.table = { (int *)&vmodem_sram_leakage_data[0], (int *)&vmodem_sram_leakage_data[1],
		(int *)&vmodem_sram_leakage_data[2] },
};


typedef struct voltage_row_s {
	int mV[VSIZE];
} vrow_t;

typedef struct temperature_row_s {
	int deg;
	int mA[VSIZE];
} trow_t;


typedef struct sptab_s {
	int vsize;
	int tsize;
	int *data;		/* array[VSIZE + TSIZE + (VSIZE*TSIZE)] */
	vrow_t *vrow;	/* pointer to voltage row of data */
	trow_t *trow;	/* pointer to temperature row of data */
} sptbl_t;

#define trow(tab, ti)		((tab)->trow[ti])
#define mA(tab, vi, ti)	((tab)->trow[ti].mA[vi])
#define mV(tab, vi)			((tab)->vrow[0].mV[vi])
#define deg(tab, ti)		((tab)->trow[ti].deg)
#define vsize(tab)			((tab)->vsize)
#define tsize(tab)			((tab)->tsize)
#define tab_validate(tab)	(!!(tab) && (tab)->data != NULL)

static inline void spower_tab_construct(sptbl_t (*tab)[], spower_raw_t *raw)
{
	int i;
	sptbl_t *ptab = (sptbl_t *)tab;

	for (i = 0; i < raw->table_size; i++) {
		ptab->vsize = raw->vsize;
		ptab->tsize = raw->tsize;
		ptab->data = raw->table[i];
		ptab->vrow = (vrow_t *)ptab->data;
		ptab->trow = (trow_t *)(ptab->data + ptab->vsize);
		ptab++;
	}
}



#endif


