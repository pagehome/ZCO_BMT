import com.cubeone.CubeOneAPI;
import java.text.SimpleDateFormat;
import java.util.Date;

public class gaTest {
    public static void main (String arg[]) {

        String encVal = null;
        String encVal2 = null;
        String decVal = null;
    
        String idxChar = null;        // Left .. 
        String idxCharSel = null;    // Right ..

        byte[] errbyte = new byte[5];
        int total = 3000000;
        int i=0, j=0;
        long startMills = 0L;
        long endmills = 0L;

        /* Test coencchar() */
        String[] inVal = {
//"123" ,
//"12", 
//"abcdefghijklmnopqrstuvwxyz",
//"abcdefghijklmnopqrstuvwxy1" 
"5086-8545-3474-1780",
};
        String[] item ={
"3DES",
"AES128","AES192","AES256",
"AES256_LE", "AES256_LN", "AES256_PART", "AES256_RE","AES256_RN",
"ARIA128","ARIA192","ARIA256",
"ARIA256_LE", "ARIA256_LN", "ARIA256_RE","ARIA256_RN",
"DES","SEED",
"SHA256", "SHA384", "SHA512"
/////////////////////////
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
/////////////////////////
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

        System.out.println("\n [CubeOne for API] Enc Test...\n");
        // CubeOneAPI.jcoinit(1, "API", "SA", "","","","","","","", 100);

        System.out.println("\n\n");
        System.out.println("-------------------------------------------------------------");
        System.out.println("------ [1] ENC/DEC TEST -------------------------------------");
        System.out.println("-------------------------------------------------------------");
        for (j=0 ; j < inVal.length ; j++) {
            for (i=0 ; i < item.length ; i++){
                System.out.println("\ninVal = ["+inVal[j]+"]");
                encVal = CubeOneAPI.coencchar(inVal[j],item[i],11,"","",errbyte);
                if(!"00000".equals(new String(errbyte))) {
                    System.out.println("#### Check this Item ::  Enc Fail ..!!!! ######################################");
                }
                System.out.println("["+item[i]+"] EncVal = ["+encVal+"] ErrCode = ["+new String(errbyte)+"]");
                //System.out.println("["+item[i]+"] EncVal = " + encVal );

//                if (!item[i].substring(0,3).equals("SHA")) {
                    decVal = CubeOneAPI.codecchar(encVal,item[i],10,"","",errbyte);
                    System.out.println("["+item[i]+"] DecVal = ["+decVal+"] ErrCode = ["+new String(errbyte)+"]");
//                } else { System.out.println(); }

                if(!"00000".equals(new String(errbyte))) {
                    System.out.println("#### Check this Item ::  Dec Fail ..!!!! ######################################");
                }
            }
        }

        System.out.println("\n\n");
        System.out.println("-------------------------------------------------------------");
        System.out.println("------ [2] PartPad TEST -------------------------------------");
        System.out.println("-------------------------------------------------------------");
        // Enc Part Pad Test 
        String PartIn = "abcde6";
        String PartItem = "AES256_LN";
        encVal = CubeOneAPI.coencchar(PartIn,PartItem,11,null,null,errbyte);
        System.out.println("["+PartItem+"] PartPad Test Input=["+PartIn+"] EncVal = ["+encVal+"] ErrCode = ["+new String(errbyte)+"]\n");

        decVal = CubeOneAPI.codecchar(encVal,PartItem,10,"","",errbyte);
        System.out.println("["+PartItem+"] DecVal = ["+decVal+"] ErrCode = ["+new String(errbyte)+"]\n");

        System.out.println("\n\n");
        System.out.println("-------------------------------------------------------------");
        System.out.println("------ [3] CheckSum TEST ------------------------------------");
        System.out.println("-------------------------------------------------------------");
        // Enc Check Sum Test 
        for (j=0 ; j < inVal.length ; j++) {
            for (i=0 ; i < item.length ; i++){
                System.out.println("\ninVal = ["+inVal[j]+"]");
                encVal  = CubeOneAPI.coencchar(inVal[j],item[i],11,"","",errbyte);
                System.out.println("["+item[i]+"] EncVal = ["+encVal+"] ErrCode = ["+new String(errbyte)+"]");

                encVal2 = CubeOneAPI.coencchar(encVal,item[i],11,"","",errbyte);
                System.out.println("["+item[i]+"] EncVal2 = ["+encVal2+"] ErrCode = ["+new String(errbyte)+"]");
                
                if("00000".equals(new String(errbyte))) {
                    System.out.println("#### Check this Item :: Double Enc ..!!!! ######################################");
                }
            }
        }


/*
        // Original ... 
        encVal = CubeOneAPI.coencchar("1234567890123","AES",11,"","",errbyte);
        System.out.println("["+item[0]+"] Check Sum Encrypted data is = ["+encVal+"] ErrCode = ["+new String(errbyte)+"]");
        encVal = CubeOneAPI.coencchar(encVal,"AES",11,"","",errbyte);
        if ((errbyte[3] == 49) && (errbyte[4] == 56) )
            System.out.println("["+item[0]+"] Check Sum Test is Ok errcode = ["+new String(errbyte)+"]\n");
        else
            System.out.println("["+item[0]+"] Check Sum Test is not Ok errcode = ["+new String(errbyte)+"]\n");

*/


        System.out.println("\n\n");
        System.out.println("-------------------------------------------------------------");
        System.out.println("------ [4] INDEX TEST ---------------------------------------");
        System.out.println("-------------------------------------------------------------");
        // Index Test 
        for (j=0 ; j < inVal.length ; j++) {
            for (i=0 ; i < item.length-3 ; i++){
                encVal =     CubeOneAPI.coencchar(inVal[j],item[i],11,"","",errbyte);

                idxChar =    CubeOneAPI.coindexchar(encVal,item[i],"", "", errbyte);
                System.out.println("["+item[i]+"] idxChar =    ["+idxChar+"] ErrCode = ["+new String(errbyte)+"]");

                idxCharSel = CubeOneAPI.coindexcharsel(inVal[j],item[i],"","",errbyte);
                System.out.println("["+item[i]+"] idxCharSel = ["+idxCharSel+"] ErrCode = ["+new String(errbyte)+"]");

                try {
                    if(!idxChar.equals(idxCharSel)) {
                        System.out.println("idxChar is not equal idxCharSel !!!!!!!!!!!!!!!!!!!!!!!!!");
                    } 
                } catch (NullPointerException e) {
                    System.out.println("idxChar is not equal idxCharSel or NULL ..!!!!!!!!!!!!!!!!!!!!!!!!!");
                }
            }
        }
    }
}
