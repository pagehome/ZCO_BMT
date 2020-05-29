import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import com.cubeone.CubeOneAPI;

public class PlainPrint {
	private void startUp() throws ClassNotFoundException, SQLException {
		Class.forName("oracle.jdbc.driver.OracleDriver");
		Connection con = DriverManager.getConnection("jdbc:oracle:thin:@192.168.57.137:1521:orcl", "scott", "one123");
		con.setAutoCommit(false);
		String SQL = "SELECT * FROM BIG_EMP8";
		Statement stmt = con.createStatement();




		ResultSet rs = stmt.executeQuery(SQL);

		int i = 0;
		while (rs.next()) {
			int pk = rs.getInt(1);
			String db_value = rs.getString(2);
			String op_value = db_value;


//			if (i++ % 30000 == 0) {
			if (i++ == 0) {
				System.out.println("pk=" + pk + ",  db_value=" + db_value + ",  op_value=" + op_value);

			} 
		}
	}

	public static void main(String[] args) throws ClassNotFoundException, SQLException {
		long start = System.currentTimeMillis();
		new PlainPrint().startUp();
		long end = System.currentTimeMillis();
		long elap = (end - start) / 1000; //
		System.out.println("DecPrint Elapsed Seconds = " + elap);
	}

}

