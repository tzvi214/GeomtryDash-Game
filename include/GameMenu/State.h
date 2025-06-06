#pragma once

class State {

public:
	State();

    // Setters
    void setStart(bool value);
    void setExit(bool value);
    void setHelp(bool value);
    void setStore(bool value);

    // Getters
    bool isStart() const;
    bool isExit() const;
    bool isHelp() const;
    bool isStore() const;

private:
	bool m_start;
	bool m_exit;
	bool m_help;
	bool m_store;
};
