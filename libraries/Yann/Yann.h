#include <IRremote.h>
#define AVANT_ROBOT 5316027 // avant de la télécommande du robot
#define AVANT_HIFI 2327580833 // avant de la télécommande de la chaine

//#define B 16754775
#define ARRIERE_ROBOT 2747854299 // arriere de la télécommande du robot
#define ARRIERE_HIFI 2685719143 // arriere de la télécommande de la chaine

//#define X 16712445
#define STOP_ROBOT 3622325019 // OK de la télécommande du robot
#define STOP_HIFI 1815043745 // stop de la télécommande de la chaine

//#define C 16720605
#define GAUCHE_ROBOT 1386468383 // gauche de la télécommande du robot
#define GAUCHE_HIFI 641543941 // gauche de la télécommande de la chaine


//#define D 16761405
#define DROITE_ROBOT 553536955 // droite de la télécommande du robot
#define DROITE_HIFI 3841588867 // droite de la télécommande de la chaine

#define VOLUME_UP_HIFI 1349163975 // volume haut de la télécommande de la chaine
#define VOLUME_DOWN_HIFI 3687529025 // volume bas de la télécommande de la chaine

#define OFF_HIFI 2272138085 // off bas de la télécommande de la chaine

#define LED_ROBOT 3238126971 // bouton 1 de la télécommande du robot
#define USB_REC_HIFI 2555128611 // USB/REC de la télécommande de la chaine
#define TOUCHE_1_ROBOT 3238126971 // bouton 1 de la télécommande du robot
#define TOUCHE_2_ROBOT 2538093563 // bouton 2 de la télécommande du robot
#define TOUCHE_3_ROBOT 4039382595 // bouton 3 de la télécommande du robot
#define TOUCHE_4_ROBOT 2534850111 // bouton 4 de la télécommande du robot
#define TOUCHE_5_ROBOT 1033561079 // bouton 5 de la télécommande du robot
#define TOUCHE_6_ROBOT 1635910171 // bouton 6 de la télécommande du robot
#define TOUCHE_7_ROBOT 2351064443 // bouton 7 de la télécommande du robot
#define TOUCHE_8_ROBOT 1217346747 // bouton 8 de la télécommande du robot
#define TOUCHE_9_ROBOT 71952287 // bouton 9 de la télécommande du robot
#define TOUCHE_0_ROBOT 465573243 // bouton 0 de la télécommande du robot0
#define TOUCHE_DIESE_ROBOT 1053031451 // bouton # de la télécommande du robot
#define TOUCHE_ETOILE_ROBOT  851901943

#define DO_0    33.70
#define DO_D_0  35.65
#define RE_0    37.71
#define RE_D_0  39.89
#define MI_0    41.20
#define FA_0    44.65
#define FA_D_0  46.25
#define SOL_0   49.00
#define SOL_D_0 52.91
#define LA_0    55.00
#define SI_B_0  58.27
#define SI_0    62.74
#define DO_1    65.41
#define DO_D_1  69.30
#define RE_1    73.42
#define RE_D_1  78.78
#define MI_1    82.41
#define FA_1    87.31
#define FA_D_1  93.50
#define SOL_1   98.00
#define SOL_D_1 104.83
#define LA_1    110.00
#define SI_B_1  117.54
#define SI_1    123.47
#define DO_2    131.81
#define DO_D_2  139.59
#define RE_2    147.83
#define RE_D_2  156.56
#define MI_2    165.81
#define FA_2    175.61
#define FA_D_2  185.00
#define SOL_2   196.00
#define SOL_D_2 208.65
#define LA_2    220.00
#define SI_B_2  233.08
#define SI_2    247.94

#define DO_3    261.626
#define DO_D_3  277.183
#define RE_3    293.665
#define RE_D_3  311.127
#define MI_3    329.628
#define FA_3    349.228
#define FA_D_3  369.994
#define SOL_3   391.995
#define SOL_D_3 415.305
#define LA_3    440.000
#define SI_B_3  466.164
#define SI_3    493.883
#define DO_4    523.251
#define DO_D_4  554.365
#define RE_4    587.330
#define RE_D_4  622.254
#define MI_4    659.456
#define FA_4    698.456
#define FA_D_4  739.989
#define SOL_4   783.991
#define SOL_D_4 830.609
#define LA_4    880.000
#define SI_B_4  932.328
#define SI_4    987.767
#define DO_5    1046.50

#define DO_D_5  1108.73
#define RE_5    1174.66
#define RE_D_5  1244.51
#define MI_5    1318.51
#define FA_5    1396.91
#define FA_D_5  1479.98
#define SOL_5   1568.66
#define SOL_D_5 1661.22
#define LA_5    1760.00
#define SI_B_5  1869.66
#define SI_5    1976.53
#define DO_6    2093.00
#define DO_D_6  2217.46
#define RE_6    2349.32
#define RE_D_6  2489.02
#define MI_6    2637.02
#define FA_6    2794.83
#define FA_D_6  2960.96
#define SOL_6   3136.96
#define SOL_D_6 3322.44
#define LA_6    3520.00
#define SI_B_6  3729.31
#define SI_6    3951.07
#define DO_7    4186.01
#define DO_D_7  4435.92
#define RE_7    4699.64
#define RE_D_7  4978.03
#define MI_7    5274.04
#define FA_7    5587.65
#define FA_D_7  5919.91
#define SOL_7   6271.93
#define SOL_D_7 6644.88
#define LA_7    7040.00
#define SI_B_7  7458.62
#define SI_7    7902.13

    /*
#define RONDE	1600
#define BLANCHE	 800
#define NOIRE	 400
#define CROCHE	 200
#define DOUBLE_CROCHE	 100
#define TRIPLE_CROCHE	  50


#define RONDE	        TEMPO*4
#define BLANCHE         TEMPO*2
#define NOIRE	        TEMPO
#define CROCHE	        TEMPO/2
#define DOUBLE_CROCHE	TEMPO/4
#define TRIPLE_CROCHE	TEMPO/8
*/
