#include "Participant.h"



// Participant::Participant(int id, int solved, int time_spent, float score, int wrong_attempts)  : _id(id), _solved(solved), _time_spent(time_spent), _score(score), _wrong_attempts(wrong_attempts) {}

Participant::Participant(const Participant& other) : _id(other._id), _solved(other._solved), _time_spent(other._time_spent), _score(other._score), _wrong_attempts(other._wrong_attempts) {}

Participant::Participant() : _id(0), _solved(0), _time_spent(0), _score(0.0), _wrong_attempts(0) {}

Participant::Participant(int id, int solved, int time_spent, float score, int wrong_attempts) {
    this->set_id(id);
    this->set_solved(solved);
    this->set_time_spent(time_spent);
    this->set_score(score);
    this->set_wrong_attempts(wrong_attempts);
}

int Participant::get_id() const { 
    return _id;
}
int Participant::get_solved() const { return _solved; }
int Participant::get_time_spent() const { return _time_spent; }
float Participant::get_score() const { return _score; }
int Participant::get_wrong_attempts() const { return _wrong_attempts; }

void Participant::set_id(int id) { _id = id; }
void Participant::set_solved(int solved) { _solved = solved; }
void Participant::set_time_spent(int time_spent) { _time_spent = time_spent; }
void Participant::set_score(float score) { _score = score; }
void Participant::set_wrong_attempts(int wrong_attempts) { _wrong_attempts = wrong_attempts; }

Participant& Participant::operator=(const Participant& other) {
    if (this == &other) return *this;
    this->_id = other.get_id();
    this->_solved = other.get_solved();
    this->_time_spent = other.get_time_spent();
    this->_score = other.get_score();
    this->_wrong_attempts = other.get_wrong_attempts();
    return *this;
}

bool Participant::operator<(const Participant& other) const {
    if (this->get_score() != other.get_score()) return this->get_score() > other.get_score();
    if (this->get_solved() != other.get_solved()) return this->get_solved() > other.get_solved();
    if (this->get_time_spent() != other.get_time_spent()) return this->get_time_spent() < other.get_time_spent();
    if (this->get_wrong_attempts() != other.get_wrong_attempts()) return this->get_wrong_attempts() < other.get_wrong_attempts();
    return this->get_id() < other.get_id();
}