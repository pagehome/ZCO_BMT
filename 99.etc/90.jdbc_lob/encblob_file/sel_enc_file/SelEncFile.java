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

public class SelEncFile {
	public static void main(String args[]){
		byte[] errbyte = new byte[6];
		CubeOneAPI coc = new CubeOneAPI();
		coc.coinit (1, "API2", "SA","","","","","","","",100);
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
		String encblob= null;

		try {
			Class.forName("oracle.jdbc.driver.OracleDriver");
			con = DriverManager.getConnection(jdb,dbid,dbpw);
			SQL = "SELECT COL_NUMBER,COL_BLOB FROM YANGBMT28 ";
			pstmt = con.prepareStatement(SQL);
			rs = pstmt.executeQuery();
			FileOutputStream fos = null;
			while(rs.next()) {
				/* File Save */
				fos = new FileOutputStream("./"+rs.getInt(1));

				oracle.sql.BLOB blob = (oracle.sql.BLOB)rs.getBlob(2); 
				buffer = new byte[(int) blob.length()];
				in = blob.getBinaryStream();
				count = in.read(buffer);
				if(count == -1)
					break;
				encblob = CubeOneAPI.coencbytes(buffer,buffer.length,"SSN",11,"","",errbyte);
				fos.write(encblob.getBytes(),0,encblob.length());
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

