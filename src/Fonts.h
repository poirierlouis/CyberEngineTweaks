#pragma once

struct Fonts
{
  ~Fonts() = default;

  const std::tuple<const ImWchar*, std::filesystem::path> GetGlyphRange(std::string aLanguage);
  void BuildFonts(SIZE aOutSize);
  void RebuildFonts(ID3D12CommandQueue* apCommandQueue, SIZE aOutSize);
  void TriggerFontRebuild();
  void LoadSystemFonts();

  const bool UseEmojiFont();
  
  const std::vector<std::string>& GetLanguages();
  const std::filesystem::path& GetDefaultLanguageFontPath(const std::string& acLanguage);

  void EnumerateSystemFonts();
  
  const std::vector<std::string>& GetSystemFonts();
  const std::filesystem::path& GetSystemFontPath(const std::string& acFontName);
  std::filesystem::path GetFontPathFromOption(const std::string& acFontOption);

  ImFont* MainFont;
  ImFont* MonospaceFont;

private:
  friend struct CET;
  Fonts(Options& aOptions, Paths& aPaths);

  Options& m_options;
  Paths& m_paths;

  bool m_rebuildFonts{ false };
  bool m_useEmojiFont{ false };
  std::vector<std::string> m_systemFonts { "Default" };
  std::unordered_map<std::string, std::filesystem::path> m_systemFontPaths { };

  std::filesystem::path m_defaultMainFontPath{ L"NotoSans-Regular.ttf" };
  std::filesystem::path m_defaultMonospaceFontPath{ L"NotoSansMono-Regular.ttf" };
  std::filesystem::path m_defaultIconFontPath{ L"materialdesignicons.ttf" };
  std::filesystem::path m_defaultEmojiFontPath{ L"C:\\Windows\\Fonts\\seguiemj.ttf" }; // tried to use noto color emoji but it wont render. only this one works

  
  std::vector<std::string> m_languages { };
  std::unordered_map<std::string, std::filesystem::path> m_defaultLanguageFontPaths { };
};
