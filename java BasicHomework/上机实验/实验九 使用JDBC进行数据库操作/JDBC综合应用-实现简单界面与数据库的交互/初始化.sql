CREATE TABLE user_table (
    id INT PRIMARY KEY AUTO_INCREMENT,
    userName VARCHAR(30) NOT NULL UNIQUE,
    userPsw VARCHAR(30) NOT NULL
);