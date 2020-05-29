import com.cubeone.CubeOneAPI;

public class encValOut {
    public static void main (String arg[]) {
        String encVal = null;
        String decVal = null;
        byte[] errbyte = new byte[5];
        int i=0;

        /* Test coencchar() */
        String inVal = "5086-8545-3474-1780";
        String[] item ={
// from YB
"3DES",
"AES128","AES192","AES256",
"AES256_LE", "AES256_LN", "AES256_PART", "AES256_RE","AES256_RN",
"ARIA128","ARIA192","ARIA256",
"ARIA256_LE", "ARIA256_LN", "ARIA256_RE","ARIA256_RN",
"DES","SEED",
"SHA256", "SHA384", "SHA512"

//////////////////////
/*
"AES_LE_P16_S16",
"AES_LE_P17_S17",
"AES_LE_P17_S16",
"AES_LE_P16_S17",
"AES_RE_P16_S16",
"AES_RE_P16_S17",
"AES_RE_P17_S16",
"AES_RE_P17_S17",
"AES_RNE_16",
"AES_RNE_17",
"AES_LNE_16",
"AES_LNE_17",
////////////////////
/*
"AES_RNE_6",
"AES_RNE_7",
"AES_LNE_6",
"AES_LNE_7",
"AES_LE_P6_S6",
"AES_LE_P6_S7",
"AES_LE_P7_S6",
"AES_LE_P7_S7",
"AES_RE_P6_S6",
"AES_RE_P6_S7",
"AES_RE_P7_S6",
"AES_RE_P7_S7"
*/
};

        System.out.println("\n [CubeOne for API] Enc Value Out...\n input value=[" + inVal + "]\n");
        // CubeOneAPI.coinit(1, "API", "SA", "","","","","","","", 100);

        System.out.println("=========================== ITEM ============================");
        for (i=0 ; i < item.length ; i++){
            System.out.println(item[i]);
        }
        System.out.println("========================= ENC VALUE =========================");
        for (i=0 ; i < item.length ; i++){
            encVal = CubeOneAPI.coencchar(inVal,item[i],11,"","",errbyte);
            System.out.println(encVal);
        }
    }
}

