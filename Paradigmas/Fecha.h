/* 
 * File:   Fecha.h
 * Author: estudiante
 *
 * Created on 23 de octubre de 2014, 09:47 AM
 */

#ifndef FECHA_H
#define	FECHA_H
#include<iostream>
using namespace std;
class Date {
public:

    Date(int y = 1990, int m = 1, int d = 1)
    : y(y), m(m), d(d) {
        this->set(y, m, d);
    }

    int get_year() {
        return y;
    }

    int get_month() {
        return m;
    }

    int get_day() {
        return d;
    }

    bool is_p_year()const {
        return y % 400 ? (y % 100 ? (y % 4 ? 0 : 1) : 0) : 1;
    }

    bool is_p_year(const int yy)const {
        return yy % 400 ? (yy % 100 ? (yy % 4 ? 0 : 1) : 0) : 1;
    }

    void show() {
        std::cout << y << '-' << m << '-' << d << std::endl;
    }

    void set(int yy, int mm, int dd) {
        if (yy <= 0)yy = 1990;
        else y = yy;
        if (mm <= 0 || mm > 12)m = 1;
        else m = mm;
        if (dd <= 0 || dd > DayforMonth(yy, mm))dd = 1;
        else d = dd;
    }

    void set_y(int yy) {
        this->set(yy, m, d);
    }

    void set_m(int mm) {
        this->set(y, mm, d);
    }

    void set_d(int dd) {
        this->set(y, m, dd);
    }
    Date operator +=(const int c);
    friend Date operator +(const int v, const Date a);
    friend Date operator +(const Date a, const int v);
    friend Date operator ++(Date &a);
    friend Date operator -(const Date a, const int v);
    friend int operator -(const Date a, const Date b);
    friend Date operator --(Date &a);
    friend bool operator>(const Date a, const Date b);
    friend bool operator >=(const Date a, const Date b);
    friend bool operator<(const Date a, const Date b);
    friend bool operator <=(const Date a, const Date b);
    friend bool operator ==(const Date a, const Date b);
    friend bool operator !=(const Date a, const Date b);
    //friend std::odtream & operator <<(std::ostream &os,const Date &a);
    //friend std::istream & operator >>(std::istream &is,const Date &a);
private:
    int y, m, d;
    int DayforMonth(int y, int m)const;
    int ToInt()const;
    void r_set();
};

#endif	/* FECHA_H */

