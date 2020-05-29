import java.sql.Connection;
import java.sql.SQLException;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

import com.cubeone.CubeOneAPI;

import java.io.File;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.IOException;

public class SelToFile {
	public static void main(String args[]){
		ResultSet rs = null;
		Connection con=null;
		PreparedStatement pstmt = null;

		String jdb="jdbc:oracle:thin:@192.168.1.70:1521:ORA11";
		String dbid="test";
		String dbpw="test";
		InputStream in = null;
		byte[] buffer;
		String SQL = "";
		int count = 0;

		try {
			Class.forName("oracle.jdbc.driver.OracleDriver");
			con = DriverManager.getConnection(jdb,dbid,dbpw);
			SQL = "SELECT COL_NUMBER, COL_BLOB FROM BMT28 ";
			//SQL = "SELECT COL_NUMBER, COL_BLOB FROM BMT28 WHERE COL_NUMBER = 5 ";
			pstmt = con.prepareStatement(SQL);
			rs = pstmt.executeQuery();
			FileOutputStream fos = null;
			while(rs.next()) {
				/* File Save */
				fos = new FileOutputStream("./"+rs.getInt(1));
				oracle.sql.BLOB blob = (oracle.sql.BLOB)rs.getBlob(2); 
				buffer = new byte[(int) blob.length()];
				in = blob.getBinaryStream();
				while(true) {
					count = in.read(buffer);
					if(count == -1)
						break;
					fos.write(buffer,0,buffer.length);
				}	
			}	
		in.close();
		fos.close();
		System.out.println("SQL END");

		}catch(SQLException ee){
			ee.printStackTrace();                                             
		}catch(Exception e){
			e.printStackTrace();         

		}finally{                                                                
			try{rs.close();}catch(Exception e){}                             
			try{pstmt.close();}catch(Exception e){}                          
			try{con.close();}catch(Exception e){}                           
		}
	}
}

