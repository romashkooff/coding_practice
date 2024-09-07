CREATE TABLE [dbo].[Student2] (
	[Id] int PRIMARY KEY NOT NULL IDENTITY (1,1),
	[FirstName] nvarchar(50) NOT NULL,
	[LastName] nvarchar(50) NOT NULL,
	[Age] int NOT NULL,
	[Gender] int
);

ALTER TABLE [dbo].[Student2]
ALTER COLUMN [Gender] int NOT NULL;

INSERT INTO [dbo].[Student2] ([FirstName], [LastName], [Age], [Gender])
VALUES (
'a1', 'b1', 20, 1), 
('a2', 'b2', 23, 2),
('a3', 'b3', 19, 2),
('a4', 'b4', 22, 1
);

UPDATE [dbo].[Student2]
SET [FirstName] = '32'
WHERE Id = 4;