// SPDX-License-Identifier: UNLICENSED
pragma solidity >=0.7.0 <0.9.0;

// Build the Contract
contract MarksManagmtSys {

    // Create a structure for student details
    struct StudentStruct {
        uint ID;
        string fName;
        string lName;
        uint marks;
    }

    address public owner; // Declare owner address
    uint public stdCount = 0; // Track the number of students

    // Create Array to store Student data
    StudentStruct[] public stdRecords;

    // Constructor to set the owner of the contract
    constructor() {
        owner = msg.sender;
    }

    // Create a function to add new records (only accessible by the owner)
    function addNewRecords(uint _ID, string memory _fName, string memory _lName, uint _marks) public {
        require(msg.sender == owner, "Only the owner can add new records.");

        // Increase the student count by 1
        stdCount += 1;

        // Adding data into array
        stdRecords.push(StudentStruct({
            ID: _ID,
            fName: _fName,
            lName: _lName,
            marks: _marks
        }));
    }

    // Function to get all student records
    function getAllRecords() public view returns (StudentStruct[] memory) {
        return stdRecords;
    }

    // Function to get the total number of students
    function getStudentCount() public view returns (uint) {
        return stdCount;
    }
}
