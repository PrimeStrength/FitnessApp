
export enum Page {
    Dashboard,
    Logs,
    Settings
}


export const pages: Page[] =
    [Page.Dashboard, Page.Logs, Page.Settings];

export function pageName(page: Page) {
    switch (page) {
        case Page.Dashboard:
            return "Dashboard";
        case Page.Logs:
            return "Logs";
        case Page.Settings:
            return "Settings";
    }
}
