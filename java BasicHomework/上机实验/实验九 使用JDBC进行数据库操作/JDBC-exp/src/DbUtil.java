import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class DbUtil {
    private static String jdbcName = "com.mysql.cj.jdbc.Driver";
    private static String url = "jdbc:mysql://127.0.0.1:3306/db_stu?useUnicode=true&characterEncoding=utf-8";
    private static String userName = "root";
    private static String userPwd = "hdj20040223";
    private static Connection con = null;

    public static Connection getCon() throws Exception {
        Class.forName(jdbcName);
        con = DriverManager.getConnection(url, userName, userPwd);
        return con;
    }

    public static void closeCon() throws SQLException {
        if (con != null) {
            con.close();
        }
    }
}
