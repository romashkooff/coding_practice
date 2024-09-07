CREATE TABLE [dbo].[Subjects] (
	[SubjectID] int PRIMARY KEY,
	[Title] varchar(255)
);

EXEC sp_rename 'Subjects.SubjectID', 'ID', 'COLUMN'

ALTER TABLE [dbo].[Subjects]
ALTER COLUMN [Title] varchar(50);

INSERT INTO [dbo].[Subjects] ([ID], [Title])
VALUES ('1','Math');

INSERT INTO [dbo].[Subjects] ([ID], [Title])
VALUES ('2','Physics');

INSERT INTO [dbo].[Subjects] ([ID], [Title])
VALUES ('3','Foreign language');

INSERT INTO [dbo].[Subjects] ([ID], [Title])
VALUES ('4','History');

INSERT INTO [dbo].[Subjects] ([ID], [Title])
VALUES ('5','Physical education');

ALTER TABLE [dbo].[Subjects]
DROP CONSTRAINT [PK__Subjects__AC1BA38864611429];

ALTER TABLE [dbo].[Subjects] DROP COLUMN [ID];

ALTER TABLE [dbo].[Subjects]
ADD [Id] int NOT NULL PRIMARY KEY IDENTITY(1,1);

ALTER TABLE [dbo].[Subjects] ALTER COLUMN [Title] varchar(50) NOT NULL;