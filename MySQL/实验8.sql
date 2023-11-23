-- 1．创建视图info_view，显示年龄大于20岁的聘任人员id、name、sex、address信息。
CREATE VIEW info_view AS
SELECT id, name, sex, address
FROM Work_Info
WHERE age > 20;

-- 2．查看视图info_view的基本结构和详细结构。
-- 查看基本结构
DESC info_view;

-- 查看详细结构
SHOW FULL COLUMNS FROM info_view;

-- 3．查看视图info_view的所有记录。
SELECT * FROM info_view;

-- 4．修改视图info_view，满足年龄小于20岁的聘任人员id、name、sex、address信息。
CREATE OR REPLACE VIEW info_view AS
SELECT id, name, sex, address
FROM Work_Info
WHERE age < 20;

-- 5．更新视图，将id号为3的聘任员的性别，由“男”改为“女”。（通过视图对基本表进行插入、更新、删除数据操作）
UPDATE info_view
SET sex = '女'
WHERE id = 3;

-- 6．删除info_view视图。
DROP VIEW IF EXISTS info_view;

