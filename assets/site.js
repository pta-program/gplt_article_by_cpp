(function () {
  'use strict';

  var button = document.getElementById('theme-toggle');
  if (!button) return;
  var icon = button.querySelector('.theme-toggle__icon');
  var text = button.querySelector('.theme-toggle__text');

  function isDark() {
    return document.documentElement.dataset.theme === 'dark';
  }

  function updateButton() {
    var dark = isDark();
    icon.textContent = dark ? '☀' : '☾';
    text.textContent = dark ? '亮色模式' : '暗黑模式';
    button.setAttribute('aria-label', dark ? '切换亮色模式' : '切换暗黑模式');
    button.setAttribute('title', dark ? '切换亮色模式' : '切换暗黑模式');
  }

  function syncMermaidTheme() {
    if (window.mermaid && typeof window.mermaid.initialize === 'function') {
      window.mermaid.initialize({
        startOnLoad: false,
        theme: isDark() ? 'dark' : 'default'
      });
    }
  }

  function setTheme(dark, persist) {
    document.documentElement.dataset.theme = dark ? 'dark' : 'light';
    document.body.classList.toggle('dark-mode', dark);
    if (persist) {
      try { localStorage.setItem('gplt-theme', dark ? 'dark' : 'light'); } catch (error) {}
    }
    syncMermaidTheme();
    updateButton();
  }

  button.addEventListener('click', function () { setTheme(!isDark(), true); });
  document.addEventListener('keydown', function (event) {
    if ((event.ctrlKey || event.metaKey) && event.key.toLowerCase() === 'd') {
      event.preventDefault();
      setTheme(!isDark(), true);
    }
  });

  try {
    window.matchMedia('(prefers-color-scheme: dark)').addEventListener('change', function (event) {
      if (!localStorage.getItem('gplt-theme')) setTheme(event.matches, false);
    });
  } catch (error) {}

  setTheme(isDark(), false);
}());
