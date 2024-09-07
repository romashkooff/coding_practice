CREATE TABLE [dbo].[Class2] (
	[Id] int NOT NULL PRIMARY KEY IDENTITY(1,1),
	[Title] nvarchar(50) NOT NULL,
	[StudentId] int NOT NULL
);

INSERT INTO [dbo].[Class2] ([Title], [StudentId])
VALUES (
'8A', 1),
('9B', 2
);

UPDATE [dbo].[Class2]
SET [StudentId] = 3
WHERE [Id] = 2;

ALTER TABLE [dbo].[Class2]
ALTER COLUMN [StudentId] int NOT NULL;

ALTER TABLE [dbo].[Class2]
ADD CONSTRAINT FK_Student2Id FOREIGN KEY (StudentId) REFERENCES Student2(Id);

SELECT Class2.StudentId, Student2.Id FROM Student2
JOIN Class2 ON Class2.StudentId = Student2.Id;