import java.math.BigDecimal;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;



public class PlainInsert {
	private void startUp() throws ClassNotFoundException, SQLException {
		Class.forName("oracle.jdbc.driver.OracleDriver");
		Connection con = DriverManager.getConnection("jdbc:oracle:thin:@192.168.57.137:1521:orcl", "scott", "one123");
		con.setAutoCommit(false);
		String SQL = "INSERT INTO BIG_EMP8(EMPNO, ENAME, JOB, MGR, HIREDATE, SAL, COMM, DEPTNO, GROUPNO) VALUES ( ? , ? , ? , ? , ? , ? , ? , ? , ? ) ";
		PreparedStatement pstmt = con.prepareStatement(SQL);
		java.sql.Date sqlDate = new java.sql.Date(new java.util.Date().getTime());




		for (long i = 0; i < 10000000; i++) {
			pstmt.setBigDecimal(1, BigDecimal.valueOf(i));

			String name = String.format("E%08d", i);
			String enc_name = name;

			if (enc_name == null || enc_name.equals("")) {
				System.out.println("ERROR: " + i + "  coencchar() null");
				continue;
			}

			pstmt.setString(2, enc_name);
			pstmt.setString(3, "JOB");
			pstmt.setInt(4, 0);
			pstmt.setDate(5, sqlDate);
			pstmt.setDouble(6, 0.1);
			pstmt.setDouble(7, 0.2);
			pstmt.setInt(8, 0);
			pstmt.setString(9, "A");
			pstmt.addBatch();
			if ((i % 30000) == 0) {
				pstmt.executeBatch();
				pstmt.clearParameters();
				con.commit();
				System.out.println("commit ::  " + i );
			}
		}
		pstmt.executeBatch();
		con.commit();
	}

	public static void main(String[] args) throws ClassNotFoundException, SQLException {
		long start = System.currentTimeMillis();
		new PlainInsert().startUp();
		long end = System.currentTimeMillis();
		long elap = (end - start) / 1000; //
		System.out.println("PlainInsert Elapsed Seconds = " + elap);
  }
}
