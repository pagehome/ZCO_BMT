import java.sql.*;
import com.cubeone.CubeOneAPI;
import oracle.sql.*;


public class co_type
{

    /****************************************************************************************
    // Oracle :: PLUG5
    static String url = "jdbc:oracle:thin:@192.168.1.45:1535:ORCL"; // URL
    static String driver = "oracle.jdbc.driver.OracleDriver";
    static String id = "scott";
    static String pass = "tiger";

    // Oracle :: AIX
    static String url = "jdbc:oracle:thin:@192.168.1.213:1522:ORA12"; // URL
    static String driver = "oracle.jdbc.driver.OracleDriver";
    static String id = "scott";
    static String pass = "tiger";

    // Tibero
    static String url = "jdbc:tibero:thin:@192.168.1.70:8629:tibero"; // URL
    static String driver = "com.tmax.tibero.jdbc.TbDriver";
    static String id = "test";
    static String pass = "test";
    //
    ****************************************************************************************/

    // Oracle :: PLUG5
    static String url = "jdbc:oracle:thin:@192.168.1.43:1535:ORCL"; // URL
    static String driver = "oracle.jdbc.driver.OracleDriver";
    static String id = "scott";
    static String pass = "tiger";
    /**************************************************************************************/

    static Connection conn = null;
    static PreparedStatement pstmt = null;
    static ResultSet rs = null;

    static String colPk;

    static String colVarchar2; 
    static String decVarchar2; 

    static String colChar; 
    static String decChar; 

    static long lColNumber; 
    static String colNumber; 
    static String decNumber; 

    static String colDate; 
    static String decDate; 

    static String format;

    static String item = "AES256" ;
    static byte[] byteErr = new byte[5];

    static String plainTable = "ZCUBE_DATATYPE8";
    static String encTable   = "ZCUBE_DATATYPE#";

    static int nRandom;
    static Timestamp timeStamp;

    public static void main(String[] args) {

        System.out.println("################################################");
        System.out.println("###### CubeOne API SelfTest : JDBC TEST ########");
        System.out.println("################################################\n");

        System.out.println("<<< CubeLog :: [url][id/pass] = [" + url + "][" + id + "/" + pass + "]"); 

        try{
            Class.forName(driver); // Load Jdbc Driver
            conn = DriverManager.getConnection(url, id, pass); // Connect DB

            nRandom = (int)(Math.random()*100);
            timeStamp = new java.sql.Timestamp(System.currentTimeMillis());

            // insertPlain();
            // insertEncTable();

            selectPlain();
            selectEncTable();

        } catch (Exception e) {
            System.out.println("<<< CubeLog :: Exception ############################################################");
            System.out.println(e.getMessage());

            e.printStackTrace();
        } finally {
            try {
                rs.close();
                pstmt.close();
                conn.close();
            } catch (Exception e) {
                // ignored ..       
                System.out.println("<<< CubeLog :: Finally ############################################################");
                System.out.println(e.getMessage());

                //e.printStackTrace();
            }
        }
    }

    static void insertPlain() throws Exception {

        System.out.println("<<< [1] Insert Plain Table  ");

        String sql = "INSERT INTO " + plainTable + " (COL_PK, COL_VARCHAR2, COL_CHAR, COL_NUMBER, COL_DATE)  VALUES( ?, ?, ?, ?, ?)";
        System.out.println(" - sql = [" + sql + "]");

        pstmt = conn.prepareStatement(sql);

        pstmt.setString(1, Integer.toString(nRandom)); // col_pk
        pstmt.setString(2, Integer.toString(nRandom)); // col_varchar2
        pstmt.setString(3, Integer.toString(nRandom)); // col_char
        //pstmt.setString(3, " ");
        pstmt.setLong(4, nRandom); // col_number
        pstmt.setTimestamp(5, timeStamp); // col_date

        System.out.println(" - [" + nRandom + "],[" + timeStamp + "]");

        pstmt.executeUpdate();

        System.out.println("--------------------------------------------------------------------------------------------------------------\n\n\n");
    }


    static void insertEncTable() throws Exception {

        System.out.println("<<< [2] Insert Enc Table  ");

        String sql = "INSERT INTO " + encTable + " (COL_PK, COL_VARCHAR2, COL_CHAR, COL_NUMBER, COL_DATE)  VALUES( ?, ?, ?, ?, ?)";
        System.out.println(" - sql = [" + sql + "]");

        pstmt = conn.prepareStatement(sql);

        pstmt.setString(1, Integer.toString(nRandom)); // col_pk
        pstmt.setString(2, CubeOneAPI.coencchar(Integer.toString(nRandom), item, 10, null, null, byteErr)); // col_varchar2
        pstmt.setString(3, CubeOneAPI.coencchar(Integer.toString(nRandom), item, 10, null, null, byteErr)); // col_char

        // Enc Number ========
        oracle.sql.NUMBER oraNumber = new oracle.sql.NUMBER(nRandom);     
        byte[] bytOraNumber = oraNumber.getBytes();
        pstmt.setString(4, CubeOneAPI.coencbytes(bytOraNumber, bytOraNumber.length,item, 10, null, null, byteErr));

        // Enc Date =======
        oracle.sql.DATE oraDate = new oracle.sql.DATE(timeStamp);     
        byte[] bytOraTimestamp = oraDate.getBytes();
        pstmt.setString(5, CubeOneAPI.coencbytes(bytOraTimestamp, bytOraTimestamp.length,item, 10, null, null, byteErr));
        // pstmt.setTimestamp(4,new java.sql.Timestamp(System.currentTimeMillis()));

        pstmt.executeUpdate();

        System.out.println("--------------------------------------------------------------------------------------------------------------\n\n\n");
    }

    static void selectPlain() throws Exception {

        System.out.println("<<< [3] Select Plain  ");
            
        String sql = "SELECT COL_PK, COL_VARCHAR2, COL_CHAR, COL_NUMBER, COL_DATE FROM " + plainTable + " ORDER BY COL_PK DESC";
            
        pstmt = conn.prepareStatement(sql);        
        rs = pstmt.executeQuery();

        System.out.println(" - sql = [" + sql + "]");
        System.out.println("-------------------------------------------------------------------------------------");
        format = String.format("%-15s%-15s%-15s%-15s%-25s", "col_pk", "col_varchar2", "char", "col_number", "col_date");
        System.out.println(format);
        System.out.println("-------------------------------------------------------------------------------------");

        int nRow = 0;                    
        while(rs.next()){ 
            colPk = rs.getString("col_pk");  
            colVarchar2 = rs.getString("col_varchar2");  
            colChar = rs.getString("col_char");  
            lColNumber = rs.getLong("col_number");  
            colDate = rs.getString("col_date");  

            format = String.format("%-15s%-15s%-15s%-15s%-25s", "["+ colPk+"]", "["+colVarchar2+"]", "[" + colChar+"]", "["+lColNumber+"]", "["+colDate+"]");
            System.out.println(format);
                
            if(++nRow > 10 ) break;
        }

        System.out.println("-------------------------------------------------------------------------------------\n\n\n");
    }

    static void selectEncTable() throws Exception {

        System.out.println("<<< [4] Select Enc Table  ");

        String sql = "SELECT COL_PK, COL_VARCHAR2, COL_CHAR, COL_NUMBER, COL_DATE FROM " + encTable + " ORDER BY COL_PK DESC";
            
        pstmt = conn.prepareStatement(sql);        
        rs = pstmt.executeQuery();

        System.out.println(" - sql = [" + sql + "]");
        System.out.println("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
        format = String.format("%-15s%-26s%-15s%-26s%-17s%-26s%-15s%-26s%-30s", "col_pk", "col_varchar2", "varchar2[dec]", "char", "char[dec]", "col_number", "number[dec]", "col_date", "date[dec]");
        System.out.println(format);
        System.out.println("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");

        int nRow = 0;                    
        while(rs.next()){ 
            colPk = rs.getString("col_pk");  

            colVarchar2 = rs.getString("col_varchar2");
            decVarchar2 = CubeOneAPI.codecchar(rs.getString("col_varchar2"), item, 10, null, null, byteErr);

            colChar = rs.getString("col_char");
            decChar = CubeOneAPI.codecchar(rs.getString("col_char"), item, 10, null, null, byteErr);

            colNumber = rs.getString("col_number");  
            lColNumber = oracle.sql.NUMBER.toLong(CubeOneAPI.codecbyte(rs.getString("col_number"), item, 10, null, null, byteErr));

            colDate = rs.getString("col_date");  
            decDate = oracle.sql.TIMESTAMP.toString(CubeOneAPI.codecbyte(rs.getString("col_date"), item, 10, null, null, byteErr));  

            format = String.format("%-15s%-26s%-15s%-26s%-17s%-26s%-15s%-26s%-30s", 
                                                  "["+colPk+"]", "["+colVarchar2+"]", "["+decVarchar2+"]", "["+colChar+"]", "["+decChar+"]", "["+colNumber+"]", "["+lColNumber+"]", "["+colDate+"]", "["+decDate+"]");
            System.out.println(format);
                
            if(++nRow > 10 ) break;
        }

        System.out.println("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
    }
}
