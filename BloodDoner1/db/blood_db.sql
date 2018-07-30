-- phpMyAdmin SQL Dump
-- version 4.5.1
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: Jul 23, 2017 at 12:00 AM
-- Server version: 10.1.13-MariaDB
-- PHP Version: 5.6.20

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `blood_db`
--

-- --------------------------------------------------------

--
-- Table structure for table `reg_tb`
--

CREATE TABLE `reg_tb` (
  `Name` varchar(30) NOT NULL,
  `Mobile` int(25) NOT NULL,
  `Email` varchar(50) NOT NULL,
  `Address` varchar(250) NOT NULL,
  `BloodGrp` varchar(4) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `reg_tb`
--

INSERT INTO `reg_tb` (`Name`, `Mobile`, `Email`, `Address`, `BloodGrp`) VALUES
('', 0, '', '', ''),
('Mahmud', 19685454, 'm@gmail.com', 'Uttara', 'B-'),
('Mahar', 1685040674, 'mahar@ymail.com', '1685040674', 'AB+'),
('Ash', 1960014012, 'ash@hotmail.com', '1960014012', 'AB+'),
('Saad', 1960015012, 'raselhasandurjoy@gmail.com', '1960015012', 'A+');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `reg_tb`
--
ALTER TABLE `reg_tb`
  ADD PRIMARY KEY (`Mobile`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
