CREATE TABLE [dbo].[Students] (
	[StudentID] int PRIMARY KEY,
	[FirstName] varchar(255),
	[LastName] varchar(255),
	[StudentAge] int,
	[ClassID] int
);

EXEC sp_rename 'Students.StudentID', 'ID', 'COLUMN' 

ALTER TABLE [dbo].[Students]
ALTER COLUMN [FirstName] varchar(50) NOT NULL;

ALTER TABLE [dbo].[Students]
ALTER COLUMN [LastName] varchar(50) NOT NULL;

ALTER TABLE [dbo].[Students]
ADD [Gender] varchar(50) NOT NULL;

INSERT INTO [dbo].[Students] ([ID], [FirstName], [LastName], [StudentAge], [ClassID], [Gender])
VALUES ('1', 'May', 'Jackson', '14', '1', 'Female');

INSERT INTO [dbo].[Students] ([ID], [FirstName], [LastName], [StudentAge], [ClassID], [Gender])
VALUES ('2', 'John', 'Ambers', '13', '1', 'Male');

INSERT INTO [dbo].[Students] ([ID], [FirstName], [LastName], [StudentAge], [ClassID], [Gender])
VALUES ('3', 'Abigale', 'Mayers', '14', '1', 'Female');

INSERT INTO [dbo].[Students] ([ID], [FirstName], [LastName], [StudentAge], [ClassID], [Gender])
VALUES ('4', 'Boris', 'Hawkins', '15', '1', 'Male');

INSERT INTO [dbo].[Students] ([ID], [FirstName], [LastName], [StudentAge], [ClassID], [Gender])
VALUES ('5', 'Jack', 'Superior', '16', '2', 'Male');

INSERT INTO [dbo].[Students] ([ID], [FirstName], [LastName], [StudentAge], [ClassID], [Gender])
VALUES ('6', 'Maria', 'Kostitskaya', '15', '2', 'Female');

INSERT INTO [dbo].[Students] ([ID], [FirstName], [LastName], [StudentAge], [ClassID], [Gender])
VALUES ('7', 'Felicia', 'Anders', '16', '2', 'Female');

INSERT INTO [dbo].[Students] ([ID], [FirstName], [LastName], [StudentAge], [ClassID], [Gender])
VALUES ('8', 'Anthony', 'Stephard', '17', '2', 'Male');

INSERT INTO [dbo].[Students] ([ID], [FirstName], [LastName], [StudentAge], [ClassID], [Gender])
VALUES ('9', 'Jane', 'Solestone', '11', '3', 'Female');

INSERT INTO [dbo].[Students] ([ID], [FirstName], [LastName], [StudentAge], [ClassID], [Gender])
VALUES ('10', 'Kiara', 'Backwards', '12', '3', 'Female');

INSERT INTO [dbo].[Students] ([ID], [FirstName], [LastName], [StudentAge], [ClassID], [Gender])
VALUES ('11', 'Jim', 'Kerry', '13', '3', 'Male');

INSERT INTO [dbo].[Students] ([ID], [FirstName], [LastName], [StudentAge], [ClassID], [Gender])
VALUES ('12', 'Cole', 'Masters', '12', '3', 'Male');

INSERT INTO [dbo].[Students] ([ID], [FirstName], [LastName], [StudentAge], [ClassID], [Gender])
VALUES ('13', 'Dwane', 'Johnson', '14', '4', 'Male');

INSERT INTO [dbo].[Students] ([ID], [FirstName], [LastName], [StudentAge], [ClassID], [Gender])
VALUES ('14', 'Lily', 'Hard', '13', '4', 'Female');

INSERT INTO [dbo].[Students] ([ID], [FirstName], [LastName], [StudentAge], [ClassID], [Gender])
VALUES ('15', 'Maya', 'Bowling', '14', '4', 'Female');

INSERT INTO [dbo].[Students] ([ID], [FirstName], [LastName], [StudentAge], [ClassID], [Gender])
VALUES ('16', 'Nikolas', 'Cage', '13', '4', 'Male');

INSERT INTO [dbo].[Students] ([ID], [FirstName], [LastName], [StudentAge], [ClassID], [Gender])
VALUES ('17', 'Owen', 'Allpick', '9', '5', 'Male');

INSERT INTO [dbo].[Students] ([ID], [FirstName], [LastName], [StudentAge], [ClassID], [Gender])
VALUES ('18', 'Hazal', 'Honey', '10', '5', 'Female');

INSERT INTO [dbo].[Students] ([ID], [FirstName], [LastName], [StudentAge], [ClassID], [Gender])
VALUES ('19', 'Laura', 'Rodrigues', '11', '5', 'Female');

INSERT INTO [dbo].[Students] ([ID], [FirstName], [LastName], [StudentAge], [ClassID], [Gender])
VALUES ('20', 'Jack', 'Jackson', '10', '5', 'Male');

ALTER TABLE [dbo].[Students] DROP COLUMN [ID];

ALTER TABLE [dbo].[Students]
ADD [Id] int NOT NULL PRIMARY KEY IDENTITY(1,1); 

ALTER TABLE [dbo].[Students] ALTER COLUMN [Gender] varchar(50) NOT NULL;

ALTER TABLE [dbo].[Students] ALTER COLUMN [StudentAge] int NOT NULL;

ALTER TABLE [dbo].[Students] ADD CONSTRAINT FK_ClassID FOREIGN KEY (ClassID) REFERENCES Class(Id)