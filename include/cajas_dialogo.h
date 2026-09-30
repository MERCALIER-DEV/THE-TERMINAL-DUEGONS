#pragma once

#include <functional>
#include <string>
#include <utility>
#include <vector>

#include <ftxui/component/component.hpp>
#include <ftxui/dom/elements.hpp>

using namespace ftxui;

class cajas_dialogo {
public:
    Elements textos;

    Element texto_sit() const {
        if (textos.empty()) {
            return hbox({text("")}) | flex | border;
        }

        return hbox({flexbox(textos)}) | flex | border;
    }

    Component menu_sit(
        const std::vector<std::string>& opciones,
        int& seleccion,
        std::function<void()> al_enter
    ) {
        opciones_ = opciones;

        MenuOption options;
        options.on_enter = std::move(al_enter);
        options.entries_option.transform = [](EntryState state) {
            if (state.focused) {
                return text("> [" + state.label + "]") | bold | color(Color::White);
            }
            return text("   " + state.label);
        };

        return Menu(&opciones_, &seleccion, options);
    }

    Component renderer_sit(Component menu) {
        return Renderer(menu, [this, menu] {
            return vbox({
                menu->Render() | center | border,
                texto_sit(),
            });
        });
    }

private:
    std::vector<std::string> opciones_;
};

