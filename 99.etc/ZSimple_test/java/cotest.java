import com.cubeone.CubeOneAPI;

public class cubetest {
   public static void main (String args[]) {
      byte[] errbyte = new byte[6];
      String decVal = null;
      String encVal = null;
      /* byte */
      byte[] inByte = null;
      String encByte = null;
      byte[] decByte = null;

      String inVal = "abcde12345";
      String item = "SSN";

      CubeOneAPI.jcoinit("API");
      //CubeOneAPI.jcoinit(1,"API", "SA","","","","","","","",100);
      
      /* coencchar, codecchar Test */
      encVal = CubeOneAPI.coencchar(inVal,item,11,null,null,errbyte);
      System.out.println("["+item+"] encstr = [" + encVal + "]");
      decVal = CubeOneAPI.codecchar(encVal,item,10,null,null,errbyte);
      System.out.println("["+item+"] decstr = [" + decVal + "]");

      /* coencbytes, codecbyte Test */
      inByte = inVal.getBytes();
      encByte = CubeOneAPI.coencbytes(inByte,inByte.length,item,11,null,null,errbyte);
      System.out.println("["+item+"] encbyte = [" + encVal + "]");
      decByte = CubeOneAPI.codecchar(encVal,item,10,null,null,errbyte);
      System.out.println("["+item+"] decbyte = [" + new String(decByte) + "]");

      /* Enc Indexchar, indexchasel Test */
      encVal = CubeOneAPI.coencchar(inVal,item,11,"","",errbyte);
      String IndexText = CubeOneAPI.coindexchar(encVal, item, "", "", errbyte);
      String PIndexText = CubeOneAPI.coindexcharsel(inVal, item, "", "", errbyte);
      System.out.println("["+item+"] coindexchar Test = ["+ IndexText +"]\n");
      System.out.println("["+item+"] coindexcharsel Test = ["+ PIndexText +"]\n");
   }
}

