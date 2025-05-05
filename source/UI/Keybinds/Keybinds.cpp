#include "Keybinds.h"
#include "../Render.h"

#include "imgui.h"


Keybinds::Keybinds(ImGuiKey inputKey, KeyMode mode, bool enableMode)
    : key(inputKey), mode(mode), isEnabled(enableMode), prevKeyState(false)
{
}

void Keybinds::Update()
{
    // V�rifie l'�tat actuel de la touche
    bool keyPressed = ImGui::IsKeyDown(key);

    switch (mode)
    {
    case HOLD:
        isEnabled = keyPressed;
        break;

    case TOGGLE:
        if (keyPressed && !prevKeyState) // Si la touche vient d'�tre press�e
        {
            isEnabled = !isEnabled;
        }
        break;

    case ALWAYS:
        isEnabled = true; // Toujours activ�, peu importe les entr�es
        break;

    case NONE:
        isEnabled = false; // Toujours d�sactiv�
        break;
    }

    // Met � jour l'�tat pr�c�dent de la touche
    prevKeyState = keyPressed;
}

bool Keybinds::IsActive() const
{
    return isEnabled;
}

void Keybinds::SetKey(ImGuiKey newKey)
{
    key = newKey;
}

void Keybinds::SetMode(KeyMode newMode)
{
    mode = newMode;
}
