CREATE TABLE [dbo].[Teachers] (
	[TeacherID] int PRIMARY KEY,
	[FirstName] varchar(255),
	[LastName] varchar(255),
	[TeacherAge] int,
	[ClassID] int,
	[SubjectID] int
);

EXEC sp_rename 'Teachers.TeacherID', 'ID', 'COLUMN';

ALTER TABLE [dbo].[Teachers]
ALTER COLUMN [FirstName] varchar(50) NOT NULL;

ALTER TABLE [dbo].[Teachers]
ALTER COLUMN [LastName] varchar(50) NOT NULL;

ALTER TABLE [dbo].[Teachers]
ADD Gender varchar(50);

INSERT INTO [dbo].[Teachers] ([ID], [FirstName], [LastName], [TeacherAge], [ClassID], [SubjectID], [Gender] )
VALUES ('1', 'Radek', 'Fucik', '35', '1', '1', 'Male');

INSERT INTO [dbo].[Teachers] ([ID], [FirstName], [LastName], [TeacherAge], [ClassID], [SubjectID], [Gender] )
VALUES ('2', 'Verneja', 'Kovarova', '39', '2', '2', 'Female');

INSERT INTO [dbo].[Teachers] ([ID], [FirstName], [LastName], [TeacherAge], [ClassID], [SubjectID], [Gender] )
VALUES ('3', 'Igor', 'Jex', '41', '3', '3', 'Male');

INSERT INTO [dbo].[Teachers] ([ID], [FirstName], [LastName], [TeacherAge], [ClassID], [SubjectID], [Gender] )
VALUES ('4', 'Ron', 'Virius', '32', '4', '4', 'Male');

INSERT INTO [dbo].[Teachers] ([ID], [FirstName], [LastName], [TeacherAge], [ClassID], [SubjectID], [Gender] )
VALUES ('5', 'Jane', 'Brown', '36', '5', '5', 'Female');

ALTER TABLE [dbo].[Teachers]
DROP CONSTRAINT [PK__Teachers__EDF25944350A13DC];

ALTER TABLE [dbo].[Teachers] DROP COLUMN [ID];

ALTER TABLE [dbo].[Teachers]
ADD [Id] int NOT NULL PRIMARY KEY IDENTITY(1,1);

ALTER TABLE [dbo].[Teachers] ALTER COLUMN [TeacherAge] int NOT NULL;

ALTER TABLE [dbo].[Teachers] ALTER COLUMN [Gender] varchar(50) NOT NULL;