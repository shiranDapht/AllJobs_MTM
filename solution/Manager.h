#ifndef _MANAGER_H_
#define _MANAGER_H_

#include "Citizen.h"
#include "Employee.h"

#include <set>
#include <string>
#include <iostream>
#include <memory>

using std::set;
using std::ostream;
using std::string;
using std::shared_ptr;

namespace mtm
{

    class Manager : public Citizen
    {
    private:
        set<Employee*, Comparator> employees_t;

        /**
         * @brief print a list of employees working under this manager
         * 
         * @param os 
         * @return std::ostream& 
         */
        ostream& printEmployees(ostream &os) const;


    public:
        Manager(int id, string first_name, string last_name, int year);
        Manager(const Manager &manager) = default;
        virtual ~Manager() override = default;

        /**
         * @brief add Employee under Manager
         *
         * @param employee
         */
        void addEmployee(Employee* employee);
        /**
         * @brief remove Employee from Manager
         *
         * @param employee_id
         */
        void removeEmployee(const int employee_id);

        /**
         * @brief print to os full name and salary
         *
         * @param os
         * @return ostream&
         */
        virtual ostream& printShort(ostream& os) const override;
        /**
         * @brief print to os full name, id, birth year, salary and short print all Employees under manager
         *
         * @param os
         * @return ostream&
         */
        virtual ostream& printLong(ostream& os) const override;

        virtual Manager* clone() const override;
        //Custom methods
        /**
         * @brief checks if Employee works under Manager
         *
         * @param id
         * @return boolean
         */
        bool isEmployeeHere(int id) const;

        /**
         * @brief Get the Employee By Id
         * 
         * @param id 
         * @return Employee pointer, nullptr if employee doesn't work under this manager 
         */
        Employee* getEmployeeByIdOrNullptr(const int id) const;
        
        /**
         * @brief Get Employee By Id
         *
         * @param id
         * @return const Employee*, if employee doesn't exist return nullptr
         */
        Employee* getEmployeeById(const int id) const;

        /**
         * @brief fire all employees of manager
         * 
         * @param salary 
         */
        void fireAllEmployees(const int salary);
    };

}

#endif