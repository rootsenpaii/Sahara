#pragma once
#include <imgui.h>

enum KeyMode
{
    HOLD,   // Activ� tant que la touche est press�e
    TOGGLE, // Alterne entre activ� et d�sactiv� � chaque pression
    ALWAYS, // Toujours activ� (ignorer les entr�es de touches)
    NONE    // D�sactiv�
};

class Keybinds
{
public:
    Keybinds(ImGuiKey inputKey, KeyMode mode, bool enableMode = false);

    void Update();       // Fonction � appeler chaque frame pour v�rifier l'�tat
    bool IsActive() const; // Retourne l'�tat actuel (activ�/d�sactiv�)

    void SetKey(ImGuiKey newKey);  // Permet de changer la touche
    void SetMode(KeyMode newMode); // Permet de changer le mode

private:
    ImGuiKey key;       // Touche associ�e
    KeyMode mode;       // Mode actuel
    bool isEnabled;     // Indique si la fonction est activ�e ou non
    bool prevKeyState;  // �tat pr�c�dent de la touche (utile pour TOGGLE)
};
