import { defineConfig, loadEnv } from 'vite'
import tailwindcss from '@tailwindcss/vite'

import react from '@vitejs/plugin-react'

// https://vite.dev/config/
export default defineConfig({
  build:{
    outDir: '../../build/software/web/dist',
    emptyOutDir: true,
  },
  plugins: [
    react(),
    tailwindcss(),
  ],
})
