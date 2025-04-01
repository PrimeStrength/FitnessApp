import { Page } from "./Pages"

export type AppState = {
  selectedPage: Page
}

export const initialAppState: AppState = {
  selectedPage: Page.Dashboard
}
