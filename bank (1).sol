// SPDX-License-Identifier: MIT
pragma solidity 0.8.30;

contract Bank{
    mapping(address => uint256) private balance;
    mapping(address => bool) private isUser;

    event AccountCreated(address user, uint256 amount);
    event Withdraw(address user, uint256 amount);
    event Deposit(address user, uint256 amount);

    function createAccount() public payable {
        require(!isUser[msg.sender], "Account Already Exist!");
        isUser[msg.sender] = true;
        balance[msg.sender] = msg.value;
        emit AccountCreated(msg.sender, msg.value);
    }

    function DepositETH() public payable {
        require(isUser[msg.sender], "Please Create an Account");
        require(msg.value > 0, "Ammount Should be a Positive Number");
        balance[msg.sender] += msg.value;
        emit Deposit(msg.sender, msg.value);
    }
    
    function WithdrawETH(uint256 amount) public {
       require(isUser[msg.sender], "Please Create an Account");
       require(balance[msg.sender] >= amount, "Insufficient Balance");
       balance[msg.sender] -= amount;
       payable(msg.sender).transfer(amount);
       emit Withdraw(msg.sender, amount);
    }

    function getBalance() public view returns (uint256) {
        require(isUser[msg.sender], "Please Create an Account");
        return balance[msg.sender];
    }
}