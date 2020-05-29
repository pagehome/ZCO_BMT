import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import com.cubeone.CubeOneAPI;

public class DecPrint {
	private void startUp() throws ClassNotFoundException, SQLException {
		Class.forName("oracle.jdbc.driver.OracleDriver");
		Connection con = DriverManager.getConnection("jdbc:oracle:thin:@192.168.57.137:1521:orcl", "scott", "one123");
		con.setAutoCommit(false);
		String SQL = "SELECT * FROM BIG_EMP";
		Statement stmt = con.createStatement();

		CubeOneAPI.coinit(1, "API_SID", "API_USER", "", "", "", "", "", "", "", 100);
		byte[] errbyte = new byte[6];

		ResultSet rs = stmt.executeQuery(SQL);

		int i = 0;
		while (rs.next()) {
			int pk = rs.getInt(1);
			String db_value = rs.getString(2);
			String op_value = CubeOneAPI.codecchar(db_value, "SSN", 11, "", "", errbyte);
			
						
//			if (i++ % 30000 == 0) {
			if (i++ == 0) {
				System.out.println("pk=" + pk + ",  db_value=" + db_value + ",  op_value=" + op_value);
//				System.out.println("pk=" + pk + ",  enc=" + enc + ",  plain=" + CubeOneAPI.codecchar(enc, "SSN", 11, "", "", errbyte));
			} 
		}
	}

	public static void main(String[] args) throws ClassNotFoundException, SQLException {
		long start = System.currentTimeMillis();
		new DecPrint().startUp();
		long end = System.currentTimeMillis();
		long elap = (end - start) / 1000; //
		System.out.println("DecPrint Elapsed Seconds = " + elap);
	}

}

