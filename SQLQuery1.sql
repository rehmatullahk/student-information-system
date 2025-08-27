CREATE DATABASE student_managementsystem;
USE student_management;

CREATE TABLE Students (
    student_id INT PRIMARY KEY,
    name VARCHAR(100),
    dob DATE,
    gender VARCHAR(10),
    email VARCHAR(100),
    phone VARCHAR(15)
);


CREATE TABLE Course(
    course_id INT PRIMARY KEY,
    course_name VARCHAR(100),
    credit_hours INT
);


CREATE TABLE Enrollment(
    enrollment_id INT PRIMARY KEY,
    student_id INT,
    course_id INT,
    semester VARCHAR(10),
    FOREIGN KEY (student_id) REFERENCES Students(student_id),
    FOREIGN KEY (course_id) REFERENCES Courses(course_id)
);
INSERT INTO Students VALUES (6, 'Ali Khan', '2005-05-12', 'M', 'ali@example.com', '03001234567');
INSERT INTO Students VALUES (2, 'hadi', '2004-04-16', 'M', 'hadi@example.com', '03012041786');
INSERT INTO Students VALUES (3, 'hasnain', '2003-05-11', 'M', 'hasnain@example.com', '03081010203');
INSERT INTO Students VALUES (4, 'sara', '2002-07-27', 'F', 'sara@example.com', '03081283943');
INSERT INTO Students VALUES (5, 'Arooj', '2001-07-20', 'F', 'aroojexample.com', '03043932345');

INSERT INTO Courses VALUES (102, 'Database Systems', 3);
INSERT INTO Courses VALUES (103, 'programming fundamental', 4);
INSERT INTO Courses VALUES (104, 'claculus', 5);
INSERT INTO Courses VALUES (105, 'object oriented programming', 6);
INSERT INTO Courses VALUES (106, 'linear algebra', 7);


INSERT INTO Enrollments VALUES (1001, 1, 101, '2024');
INSERT INTO Enrollments VALUES (1002, 5, 102, '2023');
INSERT INTO Enrollments VALUES (1003, 3, 103, '2024');
INSERT INTO Enrollments VALUES (1004, 4, 104, '2024');


SELECT * FROM Students;
SELECT * FROM Courses;
SELECT * FROM Enrollments;
select * FROM students where name='amna'
update students set gender= female
where student_ID=6;


