SELECT Class.Id, Students.ClassID, Students.FirstName, Students.LastName FROM Class 
JOIN Students ON Class.Id=Students.ClassID;