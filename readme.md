
<!DOCTYPE html><html lang="en"><head><link rel="preconnect" href="https://fonts.gstatic.com" crossorigin="">
    <meta charset="utf-8">
    <title>Code Studio</title>
    <meta name="google-site-verification" content="ASe_HQRsu8j61tGt95RROjXi07M380nMuoJ0Mu9rytk">
    <meta name="google-site-verification" content="H3-dC79E1-GywjBhXeFujCs7FNUCTTxzAfGxGt4_bmc">
    <base href="/">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <!-- preconnect is a high cost, so use it wisely -->
    <link rel="preconnect" href="https://files.codingninjas.com">
    <link rel="preconnect" href="https://files.codingninjas.in">
    <link rel="preconnect" href="https://api.codingninjas.com">
    <!-- dns-prefetch is low cost -->
    <link rel="dns-prefetch" href="https://q.quora.com">
    <link rel="dns-prefetch" href="https://cds.taboola.com">
    <link rel="dns-prefetch" href="https://www.google-analytics.com">
    <link rel="dns-prefetch" href="https://www.clarity.ms">
    <link rel="dns-prefetch" href="https://ninjasfilestest.s3.amazonaws.com">
    <link rel="dns-prefetch" href="https://ninjasfiles.s3.amazonaws.com">
    <link rel="dns-prefetch" href="https://s3-ap-southeast-1.amazonaws.com">
    <!-- No need to preconnect for fonts as it is preloaded -->
    <link rel="preload" href="https://fonts.gstatic.com/s/muli/v28/7Auwp_0qiz-afTLGLQjUwkQ.woff2" as="font" type="font/woff2" crossorigin="">
    <link rel="icon" type="image/x-icon" href="favicon.ico">
    <style type="text/css">@font-face{font-family:'Material Icons';font-style:normal;font-weight:400;src:url(https://fonts.gstatic.com/s/materialicons/v140/flUhRq6tzZclQEJ-Vdg-IuiaDsNcIhQ8tQ.woff2) format('woff2');}.material-icons{font-family:'Material Icons';font-weight:normal;font-style:normal;font-size:24px;line-height:1;letter-spacing:normal;text-transform:none;display:inline-block;white-space:nowrap;word-wrap:normal;direction:ltr;-webkit-font-feature-settings:'liga';-webkit-font-smoothing:antialiased;}</style>
    <style>
      @font-face {
        font-family: 'Muli';
        font-style: normal;
        font-weight: 300;
        font-display: swap;
        src: url(https://fonts.gstatic.com/s/muli/v28/7Auwp_0qiz-afTLGLQjUwkQ.woff2)
          format('woff2');
      }
      @font-face {
        font-family: 'Muli';
        font-style: normal;
        font-weight: 400;
        font-display: swap;
        src: url(https://fonts.gstatic.com/s/muli/v28/7Auwp_0qiz-afTLGLQjUwkQ.woff2)
          format('woff');
      }
      @font-face {
        font-family: 'Muli';
        font-style: normal;
        font-weight: 600;
        font-display: swap;
        src: url(https://fonts.gstatic.com/s/muli/v28/7Auwp_0qiz-afTLGLQjUwkQ.woff2)
          format('woff');
      }
      @font-face {
        font-family: 'Muli';
        font-style: normal;
        font-weight: 700;
        font-display: swap;
        src: url(https://fonts.gstatic.com/s/muli/v28/7Auwp_0qiz-afTLGLQjUwkQ.woff2)
          format('woff');
      }
      @font-face {
        font-family: 'Muli';
        font-style: normal;
        font-weight: 800;
        font-display: swap;
        src: url(https://fonts.gstatic.com/s/muli/v28/7Auwp_0qiz-afTLGLQjUwkQ.woff2)
          format('woff');
      }
      @font-face {
        font-family: 'Muli';
        font-style: normal;
        font-weight: 900;
        font-display: swap;
        src: url(https://fonts.gstatic.com/s/muli/v28/7Auwp_0qiz-afTLGLQjUwkQ.woff2)
          format('woff');
      }
      .quote {
        font-weight: 700;
        font-size: 20px;
        line-height: 30px;
        text-align: center;
        width: 500px;
      }
      @media screen and (max-width: 600px) {
        .quote {
          font-size: 16px;
          line-height: 24px;
          width: unset;
          padding: 0 16px;
        }
      }
    </style>

    <script>
      let windowLoaded = false;
      function getQueryParams() {
        return window.location.search.length === 0
          ? {}
          : window.location.search
              .substr(1)
              .split('&')
              .map((pairString) => pairString.split('='))
              .reduce((out, pair) => {
                out[pair[0]] = pair[1];
                return out;
              }, {});
      }
      function logPAEvent(eventType, eventData = {}) {
        if (!window.naukricvId) {
          return;
        }
        const xhr = new XMLHttpRequest();
        xhr.open(
          'POST',
          'https://api.codingninjas.com/api/v3/partners/partner_analytics_data',
          true
        );
        xhr.setRequestHeader('Content-Type', 'application/json');
        xhr.send(
          JSON.stringify({
            event_type: eventType,
            naukri_cvid: window.naukricvId,
            landing_url: window.location.host + window.location.pathname,
            data: eventData,
          })
        );
      }
      const queryParams = getQueryParams();
      window.naukricvId = queryParams['cvId'];
      const marketingSource = queryParams['utm_source'];
      if (
        (marketingSource && marketingSource.toLowerCase() == 'naukri') ||
        window.naukricvId
      ) {
        window.naukricvId = window.naukricvId || marketingSource;
        const eventData = {
          user_agent: window.navigator.userAgent.toLowerCase(), // Will help to separate mobile and desktop
        };
        logPAEvent('initial_load', eventData);

        // This will tell us if loading ended to error instead of success
        const logError = (error) => {
          const errorMessage = error.message + '\n' + error.stack;
          const eventData = {
            error_message: errorMessage,
          };
          logPAEvent('load_error', eventData);
        };

        window.addEventListener('unhandledrejection', (event) => {
          event.preventDefault(); // This will not print the error in the console });

          logError(event.reason);
        });
        window.addEventListener('error', (event) => {
          event.preventDefault(); // This will not print the error in the console

          logError(event.error);
        });
      }
      window.pushEventsToQueue = true;
      window.gtmEventQueue = [];
      window.gtmEcommerceQueue = [];
      window.gtmScriptInit = false;
      const delayedPathArray = ['library'];
      let delayedPath;
      if (delayedPathArray.some((path) => location.pathname.includes(path))) {
        delayedPath = true;
      }
      if (delayedPath) {
        document.addEventListener('scroll', initGTMOnEvent);
        document.addEventListener('mousemove', initGTMOnEvent);
        document.addEventListener('touchstart', initGTMOnEvent);
      } else {
        // make sure to load it
        window.addEventListener('load', initGTMOnEvent);
        document.addEventListener('scroll', initGTMOnEvent);
        // document.addEventListener('mousemove', initGTMOnEvent);
        // document.addEventListener('touchstart', initGTMOnEvent);
      }
      function initGTMOnEvent(event) {
        windowLoaded = true;
        setTimeout(() => {
          initGTM();
        }, 10);
        event.currentTarget.removeEventListener(event.type, initGTMOnEvent); // remove the event listener that got triggered
      }
      function initGTM() {
        if (window.gtmScriptInit) {
          return false;
        }
        window.gtmScriptInit = true; // flag to ensure script does not get added to DOM more than once.
        logPAEvent('GTM_LOAD_STARTED');
        const event = new Event('gtm_script_loaded');
        (function (w, d, s, l, i) {
          w[l] = w[l] || [];
          w[l].push({ 'gtm.start': new Date().getTime(), event: 'gtm.js' });
          var f = d.getElementsByTagName(s)[0],
            j = d.createElement(s),
            dl = l != 'dataLayer' ? '&l=' + l : '';
          j.async = true;
          j.src =
            'https://www.googletagmanager.com/gtm.js?id=' +
            i +
            dl +
            '&gtm_auth=2Obs6MKGpBvVcCJFBFgP7A&gtm_preview=env-325&gtm_cookies_win=x';
          f.parentNode.insertBefore(j, f);
          j.onload = () => {
            window.dispatchEvent(event);
            window.pushEventsToQueue = false;
          };
        })(window, document, 'script', 'dataLayer', 'GTM-NSRR859');
      }
    </script>

    <script type="application/ld+json" class="website-schema">
      {
        "@context": "https://schema.org",
        "@type": "Organization",
        "name": "Coding Ninjas",
        "url": "https://www.codingninjas.com/",
        "logo": "https://files.codingninjas.in/cn-logo-dark-9824.svg",
        "sameAs": [
          "https://www.facebook.com/codingninjas",
          "https://twitter.com/CodingNinjasOff",
          "https://www.instagram.com/coding.ninjas/",
          "https://www.youtube.com/c/CodingNinjasIndia",
          "https://in.linkedin.com/company/codingninjas"
        ]
      }
    </script>
  <style>:root{--grey-900:#212121;--grey-800:#424242;--grey-700:#616161;--grey-600:#757575;--grey-500:#9e9e9e;--grey-400:#bdbdbd;--grey-300:#e0e0e0;--grey-200:#eeeeee;--grey-100:#f5f5f5;--grey-50:#fafafa;--grey-A700:#000000;--grey-A400:#343434;--grey-A200:#d0d0d0;--grey-A100:#ffffff;--orange-900:#f6430f;--orange-800:#f85618;--orange-700:#f9601e;--orange-600:#f96b24;--orange-500:#fa7328;--orange-400:#fb8848;--orange-300:#fc9d69;--orange-200:#fdb994;--orange-100:#fed5bf;--orange-50:#feeee5;--green-900:#00631f;--green-800:#00752e;--green-700:#007f36;--green-600:#008a3e;--green-500:#009245;--green-400:#26a261;--green-300:#4db37d;--green-200:#80c9a2;--green-100:#b3dec7;--green-50:#e0f2e9;--red-900:#b30108;--red-800:#be0110;--red-700:#c40114;--red-600:#cb0218;--red-500:#d0021b;--red-400:#d7283d;--red-300:#de4e5f;--red-200:#e8818d;--red-100:#f1b3bb;--red-50:#f9e1e4;--purple-900:#3400e2;--purple-800:#4600e7;--purple-700:#5000e9;--purple-600:#5a00ec;--purple-500:#6200ee;--purple-400:#7a26f1;--purple-300:#914df3;--purple-200:#b180f7;--purple-100:#d0b3fa;--purple-50:#ece0fd;--purple-10:#faf6ff;--pink-900:#8a004e;--pink-800:#b00054;--pink-700:#c50058;--pink-600:#db005c;--pink-500:#ec005e;--pink-400:#ee0978;--pink-300:#f14d91;--pink-200:#f484b1;--pink-100:#f8b5d0;--pink-50:#fce2ec}:root{--app-font:"Muli", sans-serif;--app-primary-color:#fa7328;--app-bg:#fafafa;--heading-font-size:20px;--heading-font-size-mobile:16px;--problem-left-panel-padding:16px 24px;--problem-right-panel-padding:20px;--code-editor-height:calc(100vh - var(--header-height) - 48px - 56px);--header-height:64px;--company-name-col:#9e9e9e;--company-tooltip-bg:#ffffff;--line-number-width:19px;--problem-detail-min-width-percent:30%;--try-problem-bottom:200px}body{--zen-neutral-100:#1e2124;--zen-neutral-200:#23262a;--zen-neutral-300:#282b30;--zen-neutral-400:#36393e;--zen-neutral-500:#424549;--zen-neutral-600:#626466;--zen-neutral-700:#787a7c;--zen-neutral-800:#8e9091;--zen-neutral-900:#a5a6a7;--zen-neutral-1000:#bbbcbd;--zen-neutral-1100:#d2d3d3;--zen-neutral-1200:#e8e9e9;--zen-neutral-1300:#ffffff;--zen-neutral-1400:#f8f8f8;--zen-neutral-1500:#f1f2f2;--zen-primary-25:#282627;--zen-primary-50:#332c2c;--zen-primary-100:#483733;--zen-primary-200:#5e3f35;--zen-primary-300:#734836;--zen-primary-400:#9c5a38;--zen-primary-500:#c66b3a;--zen-primary-600:#fb813e;--zen-primary-700:#fca16e;--zen-primary-800:#fdba95;--zen-primary-900:#fed3bc;--zen-primary-1000:#fedfcf;--zen-primary-1100:#feece2;--zen-primary-1200:#fff7f3;--zen-primary-1300:#fffbf8;--zen-blue-25:#2a2d36;--zen-blue-50:#2b303c;--zen-blue-100:#30374d;--zen-blue-200:#35405f;--zen-blue-300:#394871;--zen-blue-400:#425996;--zen-blue-500:#4c6bbb;--zen-blue-600:#5780e9;--zen-blue-700:#81a0ef;--zen-blue-800:#a3b9f3;--zen-blue-900:#c4d3f7;--zen-blue-1000:#d5dff9;--zen-blue-1100:#e6ecfc;--zen-blue-1200:#f5f7fe;--zen-blue-1300:#fafbfe;--zen-purple-25:#2a2c35;--zen-purple-50:#2c2d39;--zen-purple-100:#322f47;--zen-purple-200:#383156;--zen-purple-300:#3d3465;--zen-purple-400:#483b82;--zen-purple-500:#5341a0;--zen-purple-600:#6249c5;--zen-purple-700:#8977d4;--zen-purple-800:#a99bdf;--zen-purple-900:#c8bfeb;--zen-purple-1000:#d8d1f0;--zen-purple-1100:#e8e4f6;--zen-purple-1200:#f6f4fb;--zen-purple-1300:#fafafd;--zen-red-25:#2e2d31;--zen-red-50:#352e33;--zen-red-100:#483337;--zen-red-200:#5d383c;--zen-red-300:#713e3f;--zen-red-400:#994a47;--zen-red-500:#c2564f;--zen-red-600:#f6655a;--zen-red-700:#f88c83;--zen-red-800:#faaaa4;--zen-red-900:#fcc9c5;--zen-red-1000:#fdd8d6;--zen-red-1100:#fee8e6;--zen-red-1200:#fff6f5;--zen-red-1300:#fffafa;--zen-yellow-25:#2f2f31;--zen-yellow-50:#353432;--zen-yellow-100:#494135;--zen-yellow-200:#5f4f37;--zen-yellow-300:#745e39;--zen-yellow-400:#9e7d3d;--zen-yellow-500:#c99b41;--zen-yellow-600:#ffc147;--zen-yellow-700:#ffd175;--zen-yellow-800:#ffdd9a;--zen-yellow-900:#ffe9bf;--zen-yellow-1000:#ffefd1;--zen-yellow-1100:#fff6e4;--zen-yellow-1200:#fffbf4;--zen-yellow-1300:#fffdfa;--zen-green-25:#2a2f32;--zen-green-50:#2c3334;--zen-green-100:#323e39;--zen-green-200:#384b3f;--zen-green-300:#3e5944;--zen-green-400:#49744f;--zen-green-500:#568f5a;--zen-green-600:#65b168;--zen-green-700:#8cc58e;--zen-green-800:#aad4ac;--zen-green-900:#c9e4ca;--zen-green-1000:#d8ebd9;--zen-green-1100:#e8f3e8;--zen-green-1200:#f6faf6;--zen-green-1300:#fafdfa;--zen-teal-25:#202b2f;--zen-teal-50:#192a2e;--zen-teal-100:#02292a;--zen-teal-200:#034545;--zen-teal-300:#046061;--zen-teal-400:#057b7c;--zen-teal-500:#069697;--zen-teal-600:#33a9a9;--zen-teal-700:#60bcbc;--zen-teal-800:#8dcfcf;--zen-teal-900:#bbe2e2;--zen-teal-1000:#d1ebec;--zen-teal-1100:#e8f5f5;--zen-teal-1200:#f6fbfb;--zen-teal-1300:#fafdfd;--zen-pink-25:#2e2c33;--zen-pink-50:#342e36;--zen-pink-100:#473240;--zen-pink-200:#5b3849;--zen-pink-300:#6e3e53;--zen-pink-400:#964966;--zen-pink-500:#bd547a;--zen-pink-600:#ef6292;--zen-pink-700:#f389ad;--zen-pink-800:#f6a9c3;--zen-pink-900:#f9c8d9;--zen-pink-1000:#fbd8e4;--zen-pink-1100:#fde7ef;--zen-pink-1200:#fef5f9;--zen-pink-1300:#fffafc;--zen-aqua-25:#292f36;--zen-aqua-50:#2a333d;--zen-aqua-100:#2d3e50;--zen-aqua-200:#2f4b65;--zen-aqua-300:#315979;--zen-aqua-400:#3673a2;--zen-aqua-500:#3b8ecb;--zen-aqua-600:#41afff;--zen-aqua-700:#71c3ff;--zen-aqua-800:#96d3ff;--zen-aqua-900:#bce3ff;--zen-aqua-1000:#cfebff;--zen-aqua-1100:#e3f3ff;--zen-aqua-1200:#f4faff;--zen-aqua-1300:#f9fdff;--zen-text-100:#1e2124;--zen-text-400:#36393e;--zen-text-800:#8e9091;--zen-text-1000:#bbbcbd;--zen-text-1400:#f8f8f8;--zen-shadow-100:#f0f0f0}*{margin:0;padding:0}html{font-family:var(--app-font)!important}body{font-family:var(--app-font)!important;font-style:normal;width:100vw;height:100vh;background:var(--app-bg)}img{outline:none;user-select:none;-moz-user-select:none;-webkit-user-select:none;-webkit-user-drag:none;-webkit-tap-highlight-color:transparent}@media screen and (min-width: 1025px){body{overflow-x:hidden}}</style><link rel="stylesheet" href="/codestudio/styles.2cc413d1f7698890.css" media="print" onload="this.media='all'"><noscript><link rel="stylesheet" href="/codestudio/styles.2cc413d1f7698890.css"></noscript><link rel="stylesheet" href="/codestudio/vendor.10800fa9d03d48fd.css" media="print" onload="this.media='all'"><noscript><link rel="stylesheet" href="/codestudio/vendor.10800fa9d03d48fd.css"></noscript></head>
  <body>
    <!-- Google Tag Manager (noscript) -->
    <noscript><iframe
        src="https://www.googletagmanager.com/ns.html?id=GTM-NSRR859&gtm_auth=2Obs6MKGpBvVcCJFBFgP7A&gtm_preview=env-325&gtm_cookies_win=x"
        height="0"
        width="0"
        style="display: none; visibility: hidden"
      ></iframe
    ></noscript>
    <!-- End Google Tag Manager (noscript) -->
    <codingninjas-root>
      <div class="heart" style="
          height: 80vh;
          width: 100vw;
          box-sizing: border-box;
          display: flex;
          flex-direction: column;
          justify-content: center;
          align-items: center;
        ">
        <div>
          <video autoplay="" loop="" muted="" playsinline="" width="172px">
            <source src="https://files.codingninjas.in/ninjas-running-24084-24824.mp4" type="video/mp4">
          </video>
        </div>
        <div class="ninja" style="
            font-family: 'Muli', sans-serif;
            font-style: normal;
            font-weight: 700;
            font-size: 14px;
            line-height: 22px;
            color: #9696a0;
          ">
          NINJA FUN FACT
        </div>
        <div class="quote">Coding will soon be as important as reading</div>
        <div class="ninja-splash-screen-logo" style="position: absolute; bottom: 50px">
          <img src="./codestudio/assets/icons/CN-logo.svg" alt="Coding Ninjas Logo">
        </div>
      </div>
    </codingninjas-root>
  <script src="/codestudio/runtime.e37d322bfbe80dc5.js" type="module"></script><script src="/codestudio/polyfills.9c335ffe9f09be8d.js" type="module"></script><script src="/codestudio/vendor.7db1a6c092c0fb55.js" type="module"></script><script src="/codestudio/main.31822c1c9bbba7a2.js" type="module"></script>
  <script type="text/javascript">
    var myArray = [
      'Coding has over 700 languages',
      '67% of programming jobs aren’t in the technology industry',
      'Coding is behind almost everything that is powered by electricity',
      'Knowing how to code is a major requirement for astronomers',
      'The first computer didn’t use any electricity',
      'Do you know there is a coding language named “Go“',
      'Computer programming is one of the fastest-growing careers',
      'Fortran (FORmula TRANslation) was the name of the first programming language',
      'The first programmer was the daughter of a mad poet',
      'Many programming languages share the same structure',
      'Coding will soon be as important as reading',
      'How many programmers does it take to change a light bulb? None, that’s a hardware problem',
      'Why do Java developers wear glasses? Because they can’t C',
      'Software and temples are much the same — first we build them, then we pray',
      'An engineer will not call it a bug — it’s an undocumented feature',
      'In a room full of top software designers, if two agree on the same thing, that’s a majority',
      'C programmers never die. They are just cast into void',
      'Knock, knock … Who’s there? … *very long pause* … Java',
      'The best thing about a boolean is even if you are wrong, you are only off by a bit',
      'Linux is only free if your time has no value',
      'The computer was born to solve problems that did not exist before',
      'Your career will load faster than this',
    ];
    var randomItem = myArray[Math.floor(Math.random() * myArray.length)];
    document.getElementsByClassName('quote')[0].innerHTML = randomItem;
  </script>

</body></html>
