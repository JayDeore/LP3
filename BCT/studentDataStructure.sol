// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract StudentData {
    struct Student {
        uint256 studentID;
        string name;
        uint256 age;
    }

    Student[] public students;

    // Add a new student record
    function addStudent(uint256 _studentID, string memory _name, uint256 _age) public {
        students.push(Student(_studentID, _name, _age));
    }

    // Get the number of students in the array
    function getStudentCount() public view returns (uint256) {
        return students.length;
    }

    // Get student details by index
    function getStudent(uint256 index) public view returns (uint256, string memory, uint256) {
        require(index < students.length, "Student index out of bounds");
        Student memory student = students[index];
        return (student.studentID, student.name, student.age);
    }

    // Fallback function to accept Ether transactions
    receive() external payable {
        // Do something with the received Ether, for educational purposes.
    }

    // Withdraw Ether from the contract (only owner)
    function withdraw() public {
        require(msg.sender == owner, "Only the owner can withdraw");
        payable(msg.sender).transfer(address(this).balance);
    }

    address public owner;

    constructor() {
        owner = msg.sender;
    }
}

