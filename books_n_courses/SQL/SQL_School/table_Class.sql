CREATE TABLE [dbo].[Class] (
	[ClassID] int PRIMARY KEY,
	[ClassName] varchar(255),
	[QuantityStudents] int,
);

EXEC sp_rename 'Class.ClassID', 'ID', 'COLUMN';

ALTER TABLE [dbo].[Class]
ALTER COLUMN [ClassName] varchar(50);

INSERT INTO [dbo].[Class] ([ID], [ClassName])
VALUES ('1', '9A');

INSERT INTO [dbo].[Class] ([ID], [ClassName])
VALUES ('2', '10B');

INSERT INTO [dbo].[Class] ([ID], [ClassName])
VALUES ('3', '9A');

INSERT INTO [dbo].[Class] ([ID], [ClassName])
VALUES ('4', '8C');

INSERT INTO [dbo].[Class] ([ID], [ClassName])
VALUES ('5', '7B');

ALTER TABLE [dbo].[Class]
DROP CONSTRAINT [PK__Class__CB1927A09F3B6A71];

ALTER TABLE [dbo].[Class] DROP COLUMN [ID];

ALTER TABLE [dbo].[Class]
ADD [Id] int NOT NULL PRIMARY KEY IDENTITY(1,1);

ALTER TABLE [dbo].[Class] ALTER COLUMN [ClassName] varchar(50) NOT NULL
