import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class StudentManager {

    // 添加数据
    public void addStudent(int id, String name, String gender, String tel) {
        String sql = "INSERT INTO student (id, name, gender, tel) VALUES (?, ?, ?, ?)";
        try (Connection con = DbUtil.getCon(); PreparedStatement pstmt = con.prepareStatement(sql)) {
            pstmt.setInt(1, id);
            pstmt.setString(2, name);
            pstmt.setString(3, gender);
            pstmt.setString(4, tel);
            pstmt.executeUpdate();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    // 查询指定ID的记录
    public void queryStudentById(int id) {
        String sql = "SELECT * FROM student WHERE id = ?";
        try (Connection con = DbUtil.getCon(); PreparedStatement pstmt = con.prepareStatement(sql)) {
            pstmt.setInt(1, id);
            ResultSet rs = pstmt.executeQuery();
            while (rs.next()) {
                System.out.println("ID: " + rs.getInt("id") + ", Name: " + rs.getString("name") +
                        ", Gender: " + rs.getString("gender") + ", Tel: " + rs.getString("tel"));
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    // 修改李飞的电话
    public void updateStudentTel(String name, String newTel) {
        String sql = "UPDATE student SET tel = ? WHERE name = ?";
        try (Connection con = DbUtil.getCon(); PreparedStatement pstmt = con.prepareStatement(sql)) {
            pstmt.setString(1, newTel);
            pstmt.setString(2, name);
            pstmt.executeUpdate();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    // 删除指定姓名的记录
    public void deleteStudentByName(String name) {
        String sql = "DELETE FROM student WHERE name = ?";
        try (Connection con = DbUtil.getCon(); PreparedStatement pstmt = con.prepareStatement(sql)) {
            pstmt.setString(1, name);
            pstmt.executeUpdate();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    // 查询并输出所有数据
    public void queryAllStudents() {
        String sql = "SELECT * FROM student";
        try (Connection con = DbUtil.getCon(); PreparedStatement pstmt = con.prepareStatement(sql); ResultSet rs = pstmt.executeQuery()) {
            while (rs.next()) {
                System.out.println("ID: " + rs.getInt("id") + ", Name: " + rs.getString("name") +
                        ", Gender: " + rs.getString("gender") + ", Tel: " + rs.getString("tel"));
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        StudentManager manager = new StudentManager();
        
        // 添加数据
        manager.addStudent(1011, "王娟", "女", "15321001315");
        manager.addStudent(1012, "李飞", "男", "13636698870");
        manager.addStudent(1013, "张楠", "女", "15869046688");
        
        // 查询指定ID的记录
        manager.queryStudentById(1012);
        
        // 修改电话
        manager.updateStudentTel("李飞", "13770998988");
        
        // 删除记录
        manager.deleteStudentByName("张楠");
        
        // 查询并输出所有数据
        manager.queryAllStudents();
    }
}
