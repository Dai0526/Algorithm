// In this coding exercise, you will write a program to compute the results of female students. 
// You will return their names and average marks of all the females given in the input.

const students = [
    {
      name: "Anna",
      sex: "f",
      grades: [4.5, 3.5, 4]
    },
    {
      name: "Dennis",
      sex: "m",
      country: "Germany",
      grades: [5, 1.5, 4]
    },
    {
      name: "Martha",
      sex: "f",
      grades: [5, 4, 2.5, 3]
    },
    {
      name: "Brock",
      sex: "m",
      grades: [4, 3, 2]
    }
  ];


const femaleFilter = student => student.sex == "f";
const filter = (students, func) => students.filter(func);
const avgGrade = student => student.grades = (student.grades.reduce((a, b) => a + b, 0) / student.grades.length);

const femaleStudentsRec = filter(filter(students, femaleFilter), avgGrade);

console.log(students);
console.log(femaleStudentsRec);
