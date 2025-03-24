#ifndef PARTICIPANT_H
#define PARTICIPANT_H

// #include "iostream"


class Participant {
private:
    int _id;
    int _solved;
    int _time_spent;
    float _score;
    int _wrong_attempts;

public:
    Participant();
    Participant(int id, int solved, int time_spent, float score, int wrong_attempts);
    Participant(const Participant& other);
    ~Participant() = default;

    void set_id(int id);
    void set_solved(int solved);
    void set_time_spent(int time_spent);
    void set_score(float score);
    void set_wrong_attempts(int wrong_attempts);

    int get_id() const;
    int get_solved() const;
    int get_time_spent() const;
    float get_score() const;
    int get_wrong_attempts() const;

    Participant& operator=(const Participant& other);
    bool operator<(const Participant& other) const;

    // static bool write_to_file(std::ofstream& file, Participant** participants, size_t total_participants);

};

// std::ostream &operator<<(std::ostream &out, const Participant &par);

#endif
