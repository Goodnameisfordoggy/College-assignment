-- 1. 在name字段创建名为index_name的索引。
CREATE INDEX index_name ON userlogin(name);

-- 2. 创建名为index_bir的多列索引。
CREATE INDEX index_bir ON information(Birthday, Sex);

-- 3. 用ALTERTABLE语句创建名为index_id的惟一性索引。
ALTER TABLE userlogin ADD UNIQUE INDEX index_id (id);

-- 4. 删除userlogin表上的index_userlogin索引。
DROP INDEX index_userlogin ON userlogin;

-- 5. 查看userlogin表的结构的代码。
DESC userlogin;

-- 6. 删除information表上的index_name索引。
DROP INDEX index_name ON information;