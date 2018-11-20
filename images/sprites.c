/*
 * Exported with nin10kit v1.7
 * Invocation command was nin10kit --mode=sprites --bpp=8 --for_bitmap --transparent==000000 sprites GT.png Garbage.png Trash_Normal.png Trash_Inflated.png 
 * Time-stamp: Monday 11/19/2018, 21:55:10
 * 
 * Image Information
 * -----------------
 * GT.png 32@32
 * Garbage.png 32@32
 * Trash_Normal.png 32@32
 * Trash_Inflated.png 32@32
 * 
 * All bug reports / feature requests are to be filed here https://github.com/TricksterGuy/nin10kit/issues
 */

#include "sprites.h"

const unsigned short sprites_palette[179] =
{
	0x0000,0x0000,0x0400,0x0800,0x0001,0x0c00,0x0002,0x0403,
	0x0004,0x0820,0x0c20,0x1420,0x0405,0x0406,0x0407,0x0408,
	0x1440,0x1840,0x0409,0x080a,0x080b,0x1460,0x1860,0x0c0c,
	0x080d,0x080e,0x0c0e,0x1c80,0x2080,0x2080,0x2480,0x2480,
	0x0c10,0x1011,0x1484,0x1012,0x20a0,0x102f,0x1085,0x24a0,
	0x24a0,0x142f,0x28a0,0x20a1,0x20a2,0x1431,0x18a5,0x1433,
	0x24c1,0x24c1,0x1034,0x24c2,0x1cc3,0x24c3,0x14c5,0x1453,
	0x1cc6,0x28e2,0x18c7,0x28e3,0x24e4,0x24e4,0x14e6,0x1874,
	0x20e7,0x1c75,0x2d03,0x1ce8,0x2504,0x2105,0x1c93,0x2905,
	0x1c77,0x2094,0x2495,0x2508,0x2d24,0x2109,0x2925,0x24b3,
	0x2d25,0x20b5,0x20b5,0x2927,0x2529,0x2929,0x252a,0x2d46,
	0x2d47,0x28d5,0x2cd7,0x2d4a,0x24f5,0x28f5,0x2968,0x28f6,
	0x2969,0x296b,0x30f8,0x2d6b,0x316b,0x298a,0x318a,0x318b,
	0x358c,0x358d,0x3138,0x31ab,0x31cc,0x31cd,0x39cd,0x35ce,
	0x39ce,0x3dce,0x3979,0x3d79,0x3dcf,0x2dee,0x31ee,0x2def,
	0x2df0,0x39ef,0x41ef,0x3210,0x41b9,0x41b9,0x3211,0x3231,
	0x4630,0x3232,0x2e33,0x4631,0x4a31,0x45fa,0x45fa,0x2e53,
	0x2e54,0x4a52,0x4e52,0x4e1a,0x3674,0x3674,0x4a3a,0x5273,
	0x4e3b,0x3695,0x5694,0x567b,0x56b5,0x5ab5,0x5ab6,0x5a9b,
	0x5e9c,0x5ed6,0x5ebc,0x5ebc,0x62f7,0x5edc,0x6718,0x66fc,
	0x6b1c,0x6b39,0x6b3a,0x673c,0x673d,0x6b3d,0x6f3d,0x6f5d,
	0x6f7a,0x737b,0x737b,0x6f7d,0x737e,0x739c,0x779c,0x779d,
	0x739e,0x7bdd,0x7fde
};

const unsigned short sprites[2048] =
{
	0x0000,0x0000,0x0000,0x0900,0x0000,0x0000,0x0200,0x501b,
	0x0000,0x0000,0x3009,0x9176,0x0000,0x0200,0x873b,0x9191,
	0x0000,0x3000,0x9187,0x9191,0x0000,0x7615,0x9191,0x9191,
	0x0200,0x9157,0x9191,0x7691,0x1500,0x9181,0x9191,0x1b76,
	0x1b15,0x161b,0x0010,0x0000,0x7f6d,0x7b81,0x3965,0x0015,
	0x9191,0x9191,0x8d91,0x246b,0x9191,0x9191,0x9191,0x7b91,
	0x9191,0x9191,0x9191,0x9191,0x6587,0x5050,0x7f65,0x9191,
	0x1027,0x0202,0x2410,0x916c,0x0000,0x0000,0x0000,0x5e10,
	0x1c1b,0x101c,0x0000,0x0000,0x8753,0x1081,0x0000,0x0000,
	0x9153,0x1087,0x0000,0x0000,0x915e,0x1087,0x0000,0x0000,
	0x918d,0x1087,0x0000,0x0000,0x9191,0x1087,0x0000,0x0000,
	0x9191,0x1087,0x0000,0x0000,0x9191,0x1087,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x4e00,0x9191,0x8791,0x002b,0x6d09,0x9191,0x6b91,0x0009,
	0x8710,0x9191,0x3591,0x0000,0x911d,0x9191,0x1087,0x0000,
	0x913d,0x9191,0x0a7b,0x0000,0x914e,0x9191,0x096d,0x0000,
	0x914e,0x9191,0x026c,0x0000,0x9147,0x9191,0x0976,0x0000,
	0x0000,0x0000,0x0000,0x1000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x1b09,0x1b1b,0x0000,0x0000,0x7615,0x8181,
	0x0000,0x0000,0x7f15,0x9191,0x0000,0x0000,0x7f15,0x9191,
	0x0000,0x0000,0x7f15,0x9191,0x0000,0x0000,0x7f15,0x6b91,
	0x6557,0x105e,0x0000,0x0000,0x150a,0x0915,0x0000,0x0000,
	0x1b1b,0x1b1b,0x1b1b,0x1b1b,0x8181,0x8181,0x8181,0x8181,
	0x9191,0x9191,0x9191,0x9191,0x9191,0x9191,0x9191,0x9191,
	0x9191,0x9191,0x9191,0x9191,0x7b57,0x6c91,0x8157,0x9191,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x1b1b,0x1b1b,0x1b1b,0x161b,0x8181,0x8181,0x8181,0x4781,
	0x9191,0x9191,0x9191,0x5391,0x9191,0x9191,0x9191,0x5391,
	0x9191,0x9191,0x9191,0x5391,0x577b,0x5757,0x7f57,0x5391,
	0x9133,0x9191,0x107f,0x0000,0x8816,0x9191,0x2b91,0x0000,
	0x760a,0x9191,0x6591,0x0009,0x5800,0x9191,0x8891,0x002b,
	0x1b00,0x9188,0x9191,0x247b,0x0900,0x915e,0x9191,0x7b91,
	0x0000,0x7b16,0x9191,0x9191,0x0000,0x3000,0x9181,0x9191,
	0x0000,0x0000,0x7f15,0x3c91,0x0000,0x0000,0x6515,0x1d6d,
	0x0000,0x0000,0x1609,0x1016,0x0000,0x0000,0x0000,0x1600,
	0x0002,0x0000,0x0000,0x6510,0x1639,0x090a,0x1c10,0x9165,
	0x768d,0x575e,0x7f65,0x9191,0x9191,0x9191,0x9191,0x9191,
	0x7e15,0x5391,0x7b10,0x9191,0x8d16,0x5391,0x7b0a,0x9191,
	0x9153,0x5391,0x7b0a,0x9191,0x917f,0x5391,0x7b0a,0x9191,
	0x9191,0x5391,0x7b0a,0x9191,0x9191,0x5391,0x7b0a,0x9191,
	0x9191,0x5391,0x7b0a,0x9191,0x916b,0x5391,0x7b0a,0x9191,
	0x0a6c,0x0909,0x7610,0x5391,0x026c,0x0000,0x5e02,0x476d,
	0x026c,0x0000,0x1600,0x1516,0x026c,0x0000,0x0000,0x0000,
	0x026c,0x0000,0x0000,0x0000,0x026c,0x0000,0x0000,0x0000,
	0x026c,0x0000,0x0000,0x0000,0x026c,0x0000,0x0000,0x0000,
	0x0000,0x0200,0x762b,0x9191,0x0000,0x0000,0x1b00,0x7650,
	0x0000,0x0000,0x0000,0x1609,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x9191,0x9191,0x9191,0x5081,0x918d,0x8191,0x506d,0x091c,
	0x3127,0x1c2a,0x0915,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x6d31,0x3b6d,0x7b0a,0x9191,0x1610,0x1016,0x7b0a,0x9191,
	0x0000,0x1000,0x7b16,0x9191,0x0000,0x4c00,0x876b,0x9191,
	0x0000,0x6500,0x9191,0x9191,0x0000,0x6500,0x9191,0x9191,
	0x0000,0x6500,0x9191,0x9191,0x0000,0x2a00,0x2a2a,0x2a2a,
	0x026c,0x0000,0x0000,0x0000,0x026c,0x0000,0x0000,0x0000,
	0x156c,0x0010,0x0000,0x0000,0x6b7f,0x0039,0x0000,0x0000,
	0x9191,0x0047,0x0000,0x0000,0x9191,0x0047,0x0000,0x0000,
	0x9191,0x0047,0x0000,0x0000,0x2a2a,0x001c,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0e00,0x0000,0x0000,0x0400,0x6a20,
	0x0000,0x0000,0x3204,0xaa90,0x0000,0x0400,0x9b2f,0x3a94,
	0x0000,0x2500,0x929b,0x2e2e,0x0000,0x8613,0x2e99,0x2e2e,
	0x0000,0x0600,0x1713,0x2525,0x1300,0x4832,0x9072,0xa09d,
	0x722f,0xada0,0x7a94,0x5b67,0x9ca7,0x2e63,0x2e2e,0x2e2e,
	0x2e63,0x2e2e,0x2e2e,0x2e2e,0x2e2e,0x2e2e,0x2e2e,0x2e2e,
	0x2e2e,0x2e2e,0x2e2e,0x2e2e,0x2e2e,0x2e2e,0x792e,0xb2a1,
	0x2525,0x1317,0x0006,0x0000,0x9da0,0x7290,0x3248,0x0013,
	0x6356,0x9270,0xa0aa,0x2f72,0x2e2e,0x2e2e,0x632e,0xa79c,
	0x2e2e,0x2e2e,0x2e2e,0x632e,0x2e2e,0x2e2e,0x2e2e,0x2e2e,
	0x2e2e,0x2e2e,0x2e2e,0x2e2e,0xa1b2,0x2e70,0x2e2e,0x2e2e,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x000e,0x0000,0x0000,0x0000,0x1a62,0x0000,0x0000,0x0000,
	0x8baa,0x0432,0x0000,0x0000,0x9c3a,0x2d9b,0x0004,0x0000,
	0x2e2e,0x9794,0x0025,0x0000,0x2e2e,0x9c2e,0x1386,0x0000,
	0x0400,0xa252,0x2e3a,0x2e2e,0x1400,0x619d,0x2e2e,0x2e2e,
	0x5200,0x2e9e,0x2e2e,0x2e2e,0x900c,0x2e6e,0x2e2e,0x2e2e,
	0xa414,0x2e36,0x2e2e,0x2e2e,0xa137,0x2e2e,0x2e2e,0x2e2e,
	0x9459,0x2e2e,0x2e2e,0x2e2e,0x925d,0x2e2e,0x2e2e,0x2e2e,
	0x2e2e,0x4d2e,0xb2a8,0xb2b2,0x2e2e,0xad4d,0xb2b2,0xb2b2,
	0x2e2e,0xb2a8,0xb2b2,0xb2b2,0x832e,0xb2b2,0xb2b2,0xb2b2,
	0xaa2e,0xb2b2,0xb2b2,0xb2b2,0xb24d,0xb2b2,0xb2b2,0xb2b2,
	0xb26e,0xb2b2,0x89b2,0x8383,0xb270,0xb2b2,0x54b2,0x2e2e,
	0xb2b2,0x9eb2,0x2e43,0x2e2e,0xb2b2,0xb2b2,0x43aa,0x2e2e,
	0xb2b2,0xb2b2,0xa1b2,0x2e2e,0xb2b2,0xb2b2,0xb2b2,0x9ca1,
	0xb2b2,0xb2b2,0xb2b2,0xb2b2,0xb2b2,0xb2b2,0xb2b2,0xb2b2,
	0x8383,0x8383,0x8383,0x8383,0x2e2e,0x2e2e,0x2e2e,0x2e2e,
	0x2e2e,0x432e,0x52aa,0x0004,0x2e2e,0x2e2e,0x9b70,0x0013,
	0x2e2e,0x2e2e,0xaa2e,0x0051,0x9c9c,0x9c9c,0xad9c,0x0c8b,
	0xb2b2,0xb2b2,0xb2b2,0x14a5,0xb2b2,0xb2b2,0xb2b2,0x25b2,
	0x8383,0x8383,0x8383,0x52a8,0x2e2e,0x2e2e,0x2e2e,0x5f94,
	0x925d,0x2e2e,0x2e2e,0x2e2e,0x9c59,0x2e2e,0x2e2e,0x2e2e,
	0xaa37,0x2e2e,0x2e2e,0x2e2e,0xac17,0x2e43,0x2e2e,0x2e2e,
	0x900d,0x2e83,0x2e2e,0x2e2e,0x5f00,0x2eaa,0x2e2e,0x2e2e,
	0x1700,0x70a0,0x2e2e,0x2e2e,0x0600,0xad62,0x2e3a,0x2e2e,
	0xb26e,0xb2b2,0x54b2,0x2e2e,0xb254,0xb2b2,0x54b2,0x2e2e,
	0xaf2e,0xb2b2,0x70b2,0x5b5b,0x922e,0xb2b2,0xb2b2,0xb2b2,
	0x4d2e,0xb2b2,0xb2b2,0xb2b2,0x2e2e,0xb283,0xb2b2,0xb2b2,
	0x2e2e,0x942e,0xb2b2,0xb2b2,0x2e2e,0x2e2e,0xaf79,0xb2b2,
	0x2e2e,0x2e2e,0x2e2e,0x2e2e,0x2e2e,0x2e2e,0x2e2e,0x2e2e,
	0x5b5b,0x5b5b,0x5b5b,0x2e4d,0xb2b2,0xb2b2,0xb2b2,0x2e70,
	0xb2b2,0xb2b2,0xadb2,0x2e2e,0xb2b2,0xb2b2,0x6eb2,0x2e2e,
	0xb2b2,0xb2b2,0x2e83,0x2e2e,0xb2b2,0x67a1,0x2e2e,0x2e2e,
	0x2e2e,0x2e2e,0x2e2e,0x5c94,0x2e2e,0x2e2e,0x2e2e,0x529c,
	0x2e2e,0x2e2e,0x2e2e,0x25aa,0x2e2e,0x2e2e,0x432e,0x17a4,
	0x2e2e,0x2e2e,0x7a2e,0x0c90,0x2e2e,0x2e2e,0xa82e,0x0059,
	0x2e2e,0x2e2e,0x9d6e,0x0017,0x2e2e,0x3a2e,0x5faa,0x0006,
	0x0000,0x9014,0x2e99,0x2e2e,0x0000,0x2d00,0x89a0,0x2e2e,
	0x0000,0x0600,0xa53f,0x2e8f,0x0000,0x0000,0x3708,0x9e9b,
	0x0000,0x0000,0x0600,0x7d32,0x0000,0x0000,0x0000,0x1400,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x2e2e,0x2e2e,0x2e2e,0x6e5b,0x2e2e,0x2e2e,0x2e2e,0x2e2e,
	0x2e2e,0x2e2e,0x2e2e,0x2e2e,0x2e4d,0x2e2e,0x2e2e,0x2e2e,
	0x89ad,0x2e43,0x2e2e,0x2e2e,0x8b48,0xa1b0,0x6e89,0x4d61,
	0x1706,0x6a2f,0x9d90,0xaca7,0x0000,0x0d00,0x2517,0x2f2f,
	0x4367,0x2e2e,0x2e2e,0x2e2e,0x2e2e,0x2e2e,0x2e2e,0x2e2e,
	0x2e2e,0x2e2e,0x2e2e,0x2e2e,0x2e2e,0x2e2e,0x2e2e,0x632e,
	0x2e2e,0x2e2e,0x672e,0xb09e,0x6756,0x9483,0xafaf,0x488b,
	0xa7ac,0x909b,0x2f62,0x0617,0x2f2f,0x1725,0x000d,0x0000,
	0x2e2e,0x992e,0x1390,0x0000,0x2e2e,0x9d92,0x0025,0x0000,
	0x993a,0x37a0,0x0006,0x0000,0x9baa,0x0837,0x0000,0x0000,
	0x2572,0x0006,0x0000,0x0000,0x0013,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x8383,0x8383,0x8383,
	0x8300,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x8300,0x8383,
	0x0000,0x0000,0x8300,0x8383,0x8300,0x8383,0x8383,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x5470,0x4d4d,0x4d4d,
	0x8383,0x4d67,0x4d4d,0x4d4d,0x8383,0x7083,0x7070,0x7a70,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x4d6e,0x4d4d,0x4d4d,
	0x7a83,0x7070,0x7070,0x6770,0x4d4d,0x4d4d,0x4d4d,0x4d4d,
	0x4d4d,0x4d4d,0x4d4d,0x544d,0x8383,0x8383,0x8383,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x4d4d,0x4d4d,0x4d4d,0x4d4d,
	0x6767,0x6767,0x5b63,0x5b5b,0x4d4d,0x4d4d,0x4d4d,0x4d4d,
	0x5b5b,0x5b5b,0x5b5b,0x635b,0x8383,0x8383,0x8383,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x7070,0x7070,0x7070,0x7070,0x4d4d,0x4d4d,0x4d4d,0x4d4d,
	0x5b5b,0x4d54,0x8363,0x8383,0x4d4d,0x4d4d,0x7a4d,0x8383,
	0x6767,0x6767,0x837a,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x7070,0x7070,0x8383,0x8383,0x4d4d,0x4d4d,0x7a54,0x8383,
	0x8383,0x4d6e,0x4d4d,0x4d4d,0x8383,0x8383,0x8383,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x8383,0x7083,0x7070,0x7070,0x8383,0x4d63,0x4d4d,0x4d4d,
	0x8383,0x5b70,0x4d4d,0x4d4d,0x8383,0x8383,0x8383,0x8383,
	0x4d4d,0x4d4d,0x4d4d,0x4d4d,0x8383,0x8383,0x8383,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x4d4d,0x4d4d,0x4d4d,0x544d,
	0x4d4d,0x4d4d,0x4d4d,0x4d4d,0x7a83,0x7070,0x7070,0x6770,
	0x4d4d,0x4d4d,0x4d4d,0x4d4d,0x7070,0x7070,0x7070,0x7070,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x5b5b,0x5b5b,0x5b5b,0x635b,
	0x4d4d,0x4d4d,0x4d4d,0x4d4d,0x6767,0x6767,0x5b67,0x5b5b,
	0x4d4d,0x4d4d,0x7a54,0x8383,0x7070,0x7070,0x8383,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x6767,0x6767,0x837a,0x8383,
	0x4d4d,0x4d4d,0x7a4d,0x8383,0x5b5b,0x4d54,0x8363,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x8300,0x8383,0x8383,0x8383,
	0x0000,0x8383,0x8383,0x8383,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x0000,0x0000,0x8383,0x8383,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x8300,0x8383,0x8383,0x8383,0x0000,0x0000,0x8300,0x8383,
	0x0000,0x0000,0x8300,0x8383,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x8383,
	0x0000,0x0000,0x8300,0x8383,0x0000,0x8300,0x8383,0x8383,
	0x0000,0x8383,0x8383,0x8383,0x8300,0x8383,0x8383,0x8383,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x8300,0x8383,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x0000,0x0000,0x0000,0x0000,0x8383,0x8383,0x8383,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x8300,0x8383,
	0x8383,0x8383,0x8300,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x5b70,0x4d5b,0x4d4d,
	0x8383,0x4d63,0x4d4d,0x4d4d,0x8383,0x7083,0x7070,0x7070,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x4d6e,0x4d4d,0x4d4d,
	0x8383,0x707a,0x7070,0x7070,0x4d4d,0x4d4d,0x4d4d,0x4d4d,
	0x4d4d,0x4d4d,0x4d4d,0x4d4d,0x7a70,0x8383,0x8383,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x4d4d,0x4d4d,0x4d4d,0x4d4d,
	0x676e,0x6767,0x6767,0x5b5b,0x4d4d,0x4d4d,0x4d4d,0x4d4d,
	0x5b4d,0x5b5b,0x5b5b,0x5b5b,0x8383,0x8383,0x8383,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x4d4d,0x4d4d,0x4d4d,0x4d4d,
	0x5b5b,0x5b5b,0x8367,0x8383,0x4d4d,0x4d4d,0x7a4d,0x8383,
	0x675b,0x6767,0x8370,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x7083,0x7070,0x8383,0x8383,0x4d4d,0x4d4d,0x7a5b,0x8383,
	0x8383,0x4d6e,0x4d4d,0x4d4d,0x8383,0x8383,0x8383,0x707a,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x8383,0x7083,0x7070,0x8383,0x8383,0x4d67,0x4d4d,0x4d4d,
	0x8383,0x4d70,0x4d4d,0x4d4d,0x8383,0x8383,0x8383,0x8383,
	0x4d4d,0x4d4d,0x4d4d,0x4d4d,0x7070,0x7070,0x7070,0x7070,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x4d4d,0x4d4d,0x4d4d,0x5b5b,
	0x4d4d,0x4d4d,0x4d4d,0x4d4d,0x707a,0x7070,0x7070,0x6767,
	0x4d4d,0x4d4d,0x4d4d,0x4d4d,0x7070,0x7070,0x7070,0x7070,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x5b5b,0x5b5b,0x635b,0x6767,
	0x4d4d,0x4d4d,0x4d4d,0x4d4d,0x6767,0x6367,0x5b5b,0x5b5b,
	0x4d4d,0x4d4d,0x7a54,0x8383,0x7070,0x7070,0x837a,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x6767,0x6767,0x837a,0x8383,
	0x4d4d,0x4d4d,0x7a4d,0x8383,0x4d5b,0x4d4d,0x7a63,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x0000,0x8383,0x8383,0x8383,
	0x0000,0x8300,0x8383,0x8383,0x0000,0x0000,0x8383,0x8383,
	0x0000,0x0000,0x0000,0x8383,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x0000,0x8300,0x8383,0x8383,0x0000,0x0000,0x0000,0x0000,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x0000,0x0000,0x0000,0x0000,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,0x8383,
	0x0000,0x0000,0x8300,0x8383,0x0000,0x0000,0x0000,0x0000
};
