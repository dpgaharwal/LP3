// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract Bank {
    address public accholder;
    uint256 public balance; // public getter for balance

    // Event declarations
    event Deposited(address indexed accountHolder, uint256 amount);
    event Withdrawn(address indexed accountHolder, uint256 amount);

    // Constructor to set the account holder
    constructor() {
        accholder = msg.sender;  // Account holder is the address deploying the contract
        balance = 0; // Initial balance is set to 0
    }

    // Function to deposit money into the account
    function deposit() public payable {
        require(msg.value > 0, "Deposit amount should be greater than 0.");
        require(msg.sender == accholder, "You are not the account owner.");
        balance += msg.value;

        // Emit Deposit event
        emit Deposited(msg.sender, msg.value);
    }

    // Function to withdraw money from the account
    function withdraw(uint256 amount) public {
        require(msg.sender == accholder, "You are not the account owner.");
        require(amount > 0, "Withdrawal amount must be greater than 0.");
        require(balance >= amount, "Insufficient balance.");

        // Update balance before transferring to prevent reentrancy attack
        balance -= amount;
        payable(msg.sender).transfer(amount);

        // Emit Withdraw event
        emit Withdrawn(msg.sender, amount);
    }

    // Function to show the current balance of the account
    function showBalance() public view returns (uint256) {
        require(msg.sender == accholder, "You are not the account owner.");
        return balance;
    }
}
