// SPDX-License-Identifier: MIT
pragma solidity 0.8.30;

contract StudentCRUD {
    struct Student {
        string name;
        uint256 age;
    }

    Student[] private students;

    event log(string);

    function addStudent(string memory name, uint256 age) public returns (uint256) {
        students.push(Student({name: name, age: age}));
        return students.length - 1;
    }

    function readStudent(uint256 id) public view returns (Student memory) {
        require(id < students.length, "Invalid Index");
        return students[id];
    }

    function readAllStudents() public view returns (Student[] memory){
        return students;
    }

    function updateStudent(uint256 id, string memory name, uint256 age) public {
        require(id < students.length, "Invalid Index");
        students[id].name = name;
        students[id].age = age;
    }

    function deleteStudent(uint256 id) public {
        require(id < students.length, "Invalid Index");
        students[id] = students[students.length - 1];
        students.pop();
    }

    fallback() external payable {
        emit log("Fallback function called");
    }

    receive() external payable {
        emit log("recieve function called");
    }
}