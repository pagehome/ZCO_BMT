
import java.sql.*;
import java.util.*;
import java.text.*;

import com.cubeone.*;

public class InitialEncThread extends Thread {
    Connection connSel = null;
    Connection connIns = null;

    double startTime, endTime, elapTime;
    String col1, col2, col3, col4, col5, col6;

    int fetchSize = 10, insertSize = 10, logSize = 10000;
    DecimalFormat df = new DecimalFormat("#,##0");

    String range ;

    /**
     * CubeOne setting ...
     */
    byte[] errbyte = new byte[5];
    String item = "AES256";

    public InitialEncThread(String item, int fetchSize, int insertSize, String range) {
        super();
        this.item = item;
        this.range = "where autonum BETWEEN " + range;
        this.fetchSize = fetchSize;
        this.insertSize = insertSize;
    }

    public void run() {
        getConnection();
        encryptInsert();

//        encryptSelect();
//        plainSelect();
    }

    void getConnection() {
        
        /*
        HP .. 
        String url = "jdbc:oracle:thin:@192.168.1.54:1521:ORCL";
        String driver = "oracle.jdbc.driver.OracleDriver"; 
        String id = "scott"; 
        String pass = "one123";

        String url = "jdbc:sqlserver://192.168.1.48:1433;databaseName=bmt_mssql"; 
        String driver = "com.microsoft.sqlserver.jdbc.SQLServerDriver"; 
        String id = "sa"; 
        String pass = "a";

        String url = "jdbc:Altibase://192.168.1.220:20300/MYDB"; 
        String driver = "Altibase.jdbc.driver.AltibaseDriver"; 
        String id = "xserver"; 
        String pass = "xserver";

        // VMWare .. 
        String url = "jdbc:oracle:thin:@192.168.1.54:1521:ORCL";
        String driver = "oracle.jdbc.driver.OracleDriver"; 
        String id = "scott"; 
        String pass = "one123";         
        */


        // VMWare .. 
        String url = "jdbc:oracle:thin:@192.168.1.54:1521:ORCL";
        String driver = "oracle.jdbc.driver.OracleDriver"; 
        String id = "scott"; 
        String pass = "one123";         

        System.out.println("<<< CubeLog:"+ toString() +" :: Connection = [" + url + "][" + id + "/" + pass + "]"); 
        
        try {
            Class.forName(driver);
            connSel = DriverManager.getConnection(url, id, pass); // Connect DB
            connIns = DriverManager.getConnection(url, id, pass); // Connect DB

        } catch (Exception e) {
            System.out.println("<<< CubeLog:"+ toString() +" :: Exception ************************************************************");
            System.out.println("msg = [" + e.getMessage() + "]");

            e.printStackTrace();
        }
    }


    void encryptInsert() {
        System.out.println("************************************************");
        System.out.println("****** CubeOneAPI Encrypt Insert Test   ********");
        System.out.println("************************************************\n");

        PreparedStatement psSel = null;
        PreparedStatement psIns = null;
        ResultSet rs = null;

        String sqlSel = "SELECT AUTONUM, JUMIN, EMAIL, PASSWORD, ADDRESS FROM BMT_MEMBER " + range;
        String sqlIns = "INSERT INTO BMT_MEMBER_CUB VALUES(?,?,?,?,?)";

        System.out.println("<<< CubeLog:"+ toString() +" :: sqlSel = [" + sqlSel + "]");
        System.out.println("<<< CubeLog:"+ toString() +" :: sqlIns = [" + sqlIns + "]\n");

        try {
            startTime = System.currentTimeMillis();

            connIns.setAutoCommit(false);

            psSel = connSel.prepareStatement(sqlSel);
            psIns = connIns.prepareStatement(sqlIns);

            rs = psSel.executeQuery();

            // System.out.println("<<< CubeLog:"+ toString() +" :: Default => pstmt.getFetchSize() = ["
            // + psSel.getFetchSize() + "]");
            System.out.println("<<< CubeLog:"+ toString() +" :: Default => rs.getFetchSize() = [" + df.format(rs.getFetchSize()) + "]");

            rs.setFetchSize(fetchSize);

            // System.out.println("<<< CubeLog:"+ toString() +" :: pstmt.getFetchSize() = [" +
            // psSel.getFetchSize() + "]");
            System.out.println("<<< CubeLog:"+ toString() +" :: Modify  => rs.getFetchSize() = [" + df.format(rs.getFetchSize()) + "]\n");

            int j = 0;
            int loop = 0;
            int sucCnt = 0;
            int updCnt = 0;

            while (rs.next()) {
                col1 = rs.getString(1);
                col2 = rs.getString(2);
                col3 = rs.getString(3);
                col4 = rs.getString(4);
                col5 = rs.getString(5);

                j = 0;

                psIns.setString(++j, col1);
                psIns.setString(++j, CubeOneAPI.coencchar(col2, item, 11, null, null, errbyte));
                psIns.setString(++j, col3);
                psIns.setString(++j, col4);
                psIns.setString(++j, col5);

                psIns.addBatch();

                ++loop;

                if (loop % insertSize == 0) {
                    psIns.executeBatch();
                    connIns.commit();
                    psIns.clearParameters();

                    updCnt = psIns.getUpdateCount();

                    sucCnt += updCnt;
                }

                if (loop % logSize == 0) {
                    System.out.println("<<< CubeLog:"+ toString() +" :: Record = [" + df.format(loop) + "] :: Inserted  !!!");
                }
            }

            if (loop != sucCnt) {
                psIns.executeBatch();
                connIns.commit();

                updCnt = psIns.getUpdateCount();
                // System.out.println("<<< CubeLog:"+ toString() +" :: psIns.getUpdateCount() = ["
                // + updCnt + "]");

                sucCnt += updCnt;
            }

            endTime = System.currentTimeMillis();
            elapTime = (endTime - startTime) / 1000.0; //

            System.out.println(toString() + " :: ----------------------------------------");
            System.out.println(toString() + " :: -------- RESULT(encryptInsert) ---------");
            System.out.println(toString() + " :: ----------------------------------------");
            System.out.println(toString() + " ::  - item : " + item);
            System.out.println(toString() + " ::  - Total Count : " + df.format(loop));
            // System.out.println(" - Success Count : " + sucCnt);
            // System.out.println(" - Fail Cout : " + (loop - sucCnt));
            System.out.println(toString() + " ::  - Success Count : " + df.format(loop));
            System.out.println(toString() + " ::  - Fail Cout : 0");
            System.out.println(toString() + " ::  - Elapse Time : " + elapTime + "sec\n\n");

        } catch (Exception e) {
            System.out.println("<<< CubeLog:"+ toString() +" :: Exception ************************************************************");
            System.out.println("msg = [" + e.getMessage() + "]");

            e.printStackTrace();
        } finally {
            try {
                rs.close();
                psSel.close();
            } catch (Exception e) {
                // ignored ..
                System.out.println("<<< CubeLog:"+ toString() +" :: Finally ************************************************************");
                System.out.println("msg = [" + e.getMessage() + "]");
                e.printStackTrace();
            }
        }
    }

    void encryptSelect() {
        System.out.println("************************************************");
        System.out.println("****** CubeOneAPI Encrypt Select Test   ********");
        System.out.println("************************************************\n");

        PreparedStatement pstmt = null;
        ResultSet rs = null;

        try {
            startTime = System.currentTimeMillis();

            String sql = "SELECT AUTONUM, JUMIN, EMAIL, PASSWORD, ADDRESS FROM BMT_MEMBER_CUB ";

            pstmt = connSel.prepareStatement(sql);
            rs = pstmt.executeQuery();

            pstmt.getFetchSize();
            rs.getFetchSize();

            // System.out.println("<<< CubeLog:"+ toString() +" :: Default => pstmt.getFetchSize() = ["
            // + psSel.getFetchSize() + "]");
            System.out.println("<<< CubeLog:"+ toString() +" :: Default => rs.getFetchSize() = [" + df.format(rs.getFetchSize()) + "]");

            rs.setFetchSize(fetchSize);

            // System.out.println("<<< CubeLog:"+ toString() +" :: pstmt.getFetchSize() = [" +
            // psSel.getFetchSize() + "]");
            System.out.println("<<< CubeLog:"+ toString() +" :: Modify =>  rs.getFetchSize() = [" + df.format(rs.getFetchSize()) + "]");

            System.out.println("<<< CubeLog:"+ toString() +" :: sql = [" + sql + "]");
            System.out.println("--------------------------------------------------------------------------------------------------------------");

            int loop = 0;

            while (rs.next()) {
                loop++;
                col1 = rs.getString(1);
                col2 = CubeOneAPI.codecchar(rs.getString(2), item, 11, null, null, errbyte);
                col3 = rs.getString(3);
                col4 = rs.getString(4);
                col5 = rs.getString(5);

                if (loop < 10) {
                    System.out.println(col1 + "||" + col2 + "||" + rs.getString(2) + "||" + col3 + "||" + col4 + "||" + col5);
                }
            }

            endTime = System.currentTimeMillis();
            elapTime = (endTime - startTime) / 1000; //

            System.out.println(toString() + " :: ----------------------------------------");
            System.out.println(toString() + " :: -------- RESULT(encryptSelect) ---------");
            System.out.println(toString() + " :: ----------------------------------------");
            System.out.println(toString() + " ::  - item : " + item);
            System.out.println(toString() + " ::  - Total Count : " + df.format(loop));
            System.out.println(toString() + " ::  - Elapse Time : " + elapTime + "sec");

        } catch (Exception e) {
            System.out.println("<<< CubeLog:"+ toString() +" :: Exception ************************************************************");
            System.out.println("msg = [" + e.getMessage() + "]");

            e.printStackTrace();
        } finally {
            try {
                rs.close();
                pstmt.close();
            } catch (Exception e) {
                // ignored ..
                System.out.println("<<< CubeLog:"+ toString() +" :: Finally ************************************************************");
                System.out.println("msg = [" + e.getMessage() + "]");
                e.printStackTrace();
            }
        }

    }

    void plainSelect() {
        System.out.println("************************************************");
        System.out.println("****** CubeOneAPI Plain Select Test   **********");
        System.out.println("************************************************\n");

        PreparedStatement pstmt = null;
        ResultSet rs = null;

        try {
            startTime = System.currentTimeMillis();

            String sql = "SELECT AUTONUM, JUMIN, EMAIL, PASSWORD, ADDRESS FROM BMT_MEMBER";

            pstmt = connSel.prepareStatement(sql);
            rs = pstmt.executeQuery();

            pstmt.getFetchSize();
            rs.getFetchSize();

            // System.out.println("<<< CubeLog:"+ toString() +" :: Default => pstmt.getFetchSize() = ["
            // + psSel.getFetchSize() + "]");
            System.out.println("<<< CubeLog:"+ toString() +" :: Default => rs.getFetchSize() = [" + df.format(rs.getFetchSize()) + "]");

            rs.setFetchSize(fetchSize);

            // System.out.println("<<< CubeLog:"+ toString() +" :: pstmt.getFetchSize() = [" +
            // psSel.getFetchSize() + "]");
            System.out.println("<<< CubeLog:"+ toString() +" :: Modify  => rs.getFetchSize() = [" + df.format(rs.getFetchSize()) + "]");

            System.out.println("<<< CubeLog:"+ toString() +" :: sql = [" + sql + "]");
            System.out.println("--------------------------------------------------------------------------------------------------------------");

            int loop = 0;

            while (rs.next()) {
                loop++;
                col1 = rs.getString(1);
                col2 = rs.getString(2);
                col3 = rs.getString(3);
                col4 = rs.getString(4);
                col5 = rs.getString(5);

                if (loop < 10) {
                    System.out.println(col1 + "||" + col2 + "||" + rs.getString(2) + "||" + col3 + "||" + col4 + "||" + col5);
                }
            }

            endTime = System.currentTimeMillis();
            elapTime = (endTime - startTime) / 1000; //

            System.out.println(toString() + " :: ----------------------------------------");
            System.out.println(toString() + " :: -------- RESULT(plainSelect) -----------");
            System.out.println(toString() + " :: ----------------------------------------");
            System.out.println(toString() + " ::  - item : " + item);
            System.out.println(toString() + " ::  - Total Count : " + df.format(loop));
            System.out.println(toString() + " ::  - Elapse Time : " + elapTime + "sec");

        } catch (Exception e) {
            System.out.println("<<< CubeLog:"+ toString() +" :: Exception ************************************************************");
            System.out.println("msg = [" + e.getMessage() + "]");

            e.printStackTrace();
        } finally {
            try {
                rs.close();
                pstmt.close();
            } catch (Exception e) {
                // ignored ..
                System.out.println("<<< CubeLog:"+ toString() +" :: Finally ************************************************************");
                System.out.println("msg = [" + e.getMessage() + "]");
                e.printStackTrace();
            }
        }
    }
}
