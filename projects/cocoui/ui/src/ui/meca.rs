use crate::ui::gtk::prelude::*;
use std::cell::RefCell;

use state_manager::state::StateManagerInstance;

thread_local!(
    static PMECA: RefCell<MecaWindow> = RefCell::new(MecaWindow::new());
    static SMECA: RefCell<MecaWindow> = RefCell::new(MecaWindow::new());
);

struct MecaWindow {
    window: Option<gtk::Window>,
    state: Option<StateManagerInstance>,
    principal: bool,
}

impl MecaWindow {
    fn new() -> MecaWindow {
        MecaWindow {
            window: None,
            state: None,
            principal: true,
        }
    }

    fn init(&mut self, state: StateManagerInstance, principal: bool) {
        self.state = Some(state);
        self.principal = principal;
    }

    fn show(&mut self) {
        match self.window {
            Some(ref mut w) => w.present(),
            None => {
                let glade_src = include_str!("glade/meca.glade");
                let builder = gtk::Builder::new_from_string(glade_src);
                let window: gtk::Window = builder.get_object("mecaWindow").unwrap();

                if self.principal {
                    window.set_title("Meca (Principal)");
                }
                else {
                    window.set_title("Meca (PMI)");
                }

                window.set_position(gtk::WindowPosition::Center);


                if self.principal {
                    window.connect_delete_event(|_, _| {
                        PMECA.with(|boards| {
                            let mut boards = boards.borrow_mut();
                            boards.delete_event();
                        });
                    Inhibit(false)
                    });
                }
                else {
                    window.connect_delete_event(|_, _| {
                        SMECA.with(|boards| {
                            let mut boards = boards.borrow_mut();
                            boards.delete_event();
                        });
                        Inhibit(false)
                    });
                }

                window.show_all();
                self.window = Some(window);
            }
        }
    }

    fn delete_event(&mut self) {
        self.window = None;
    }
}

pub fn show(principal: bool) {
    if principal {
        PMECA.with(|m| {
            let mut m = m.borrow_mut();
            m.show();
        });
    }
    else {
        SMECA.with(|m| {
            let mut m = m.borrow_mut();
            m.show();
        });
    }
}

pub fn init(state: StateManagerInstance) {
    let pstate = state.clone();
    PMECA.with(|m| {
        let mut m = m.borrow_mut();
        m.init(pstate, true);
    });

    let sstate = state.clone();
    SMECA.with(|m| {
        let mut m = m.borrow_mut();
        m.init(sstate, false);
    });
}

