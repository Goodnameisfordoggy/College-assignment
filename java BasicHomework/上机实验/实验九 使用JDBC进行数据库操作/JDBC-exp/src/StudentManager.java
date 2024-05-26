import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class StudentManager {

    // �������
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

    // ��ѯָ��ID�ļ�¼
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

    // �޸���ɵĵ绰
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

    // ɾ��ָ�������ļ�¼
    public void deleteStudentByName(String name) {
        String sql = "DELETE FROM student WHERE name = ?";
        try (Connection con = DbUtil.getCon(); PreparedStatement pstmt = con.prepareStatement(sql)) {
            pstmt.setString(1, name);
            pstmt.executeUpdate();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    // ��ѯ�������������
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
        
        // �������
        manager.addStudent(1011, "����", "Ů", "15321001315");
        manager.addStudent(1012, "���", "��", "13636698870");
        manager.addStudent(1013, "���", "Ů", "15869046688");
        
        // ��ѯָ��ID�ļ�¼
        manager.queryStudentById(1012);
        
        // �޸ĵ绰
        manager.updateStudentTel("���", "13770998988");
        
        // ɾ����¼
        manager.deleteStudentByName("���");
        
        // ��ѯ�������������
        manager.queryAllStudents();
    }
}
