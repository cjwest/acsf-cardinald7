<?php
/**
 * SAML 1.1 remote IdP metadata for SimpleSAMLphp.
 *
 * Remember to remove the IdPs you don't use from this file.
 *
 * See: https://simplesamlphp.org/docs/stable/simplesamlphp-reference-idp-remote
 */

/*
$metadata['theproviderid-of-the-idp'] = [
    'SingleSignOnService' => 'https://idp.example.org/shibboleth-idp/SSO',
    'certificate' => 'example.pem',
];
*/

$metadata['https://idp.stanford.edu/'] = [
  'entityid' => 'https://idp.stanford.edu/',
  'contacts' => [],
  'metadata-set' => 'shib13-idp-remote',
  'SingleSignOnService' => [
    0 => [
      'Binding' => 'urn:mace:shibboleth:1.0:profiles:AuthnRequest',
      'Location' => 'https://idp.stanford.edu/idp/profile/Shibboleth/SSO',
    ],
    1 => [
      'Binding' => 'urn:oasis:names:tc:SAML:2.0:bindings:HTTP-POST',
      'Location' => 'https://idp.stanford.edu/idp/profile/SAML2/POST/SSO',
    ],
    2 => [
      'Binding' => 'urn:oasis:names:tc:SAML:2.0:bindings:HTTP-POST-SimpleSign',
      'Location' => 'https://idp.stanford.edu/idp/profile/SAML2/POST-SimpleSign/SSO',
    ],
    3 => [
      'Binding' => 'urn:oasis:names:tc:SAML:2.0:bindings:HTTP-Redirect',
      'Location' => 'https://idp.stanford.edu/idp/profile/SAML2/Redirect/SSO',
    ],
  ],
  'ArtifactResolutionService' => [],
  'keys' => [
    0 => [
      'encryption' => TRUE,
      'signing' => TRUE,
      'type' => 'X509Certificate',
      'X509Certificate' => '
MIIDnzCCAoegAwIBAgIJAJl9YtyaxKsZMA0GCSqGSIb3DQEBBQUAMGYxCzAJBgNV
BAYTAlVTMRMwEQYDVQQIDApDYWxpZm9ybmlhMREwDwYDVQQHDAhTdGFuZm9yZDEU
MBIGA1UECgwLSVQgU2VydmljZXMxGTAXBgNVBAMMEGlkcC5zdGFuZm9yZC5lZHUw
HhcNMTMwNDEwMTYzMTAwWhcNMzMwNDEwMTYzMTAwWjBmMQswCQYDVQQGEwJVUzET
MBEGA1UECAwKQ2FsaWZvcm5pYTERMA8GA1UEBwwIU3RhbmZvcmQxFDASBgNVBAoM
C0lUIFNlcnZpY2VzMRkwFwYDVQQDDBBpZHAuc3RhbmZvcmQuZWR1MIIBIjANBgkq
hkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAm6466Bd6mDwNOR2qZZy1WRZdjyrG2/xW
amGEMekg38fyuoSCIiMcgeA9UIUbiRCpAN87yI9HPcgDEdrmCK3Ena3J2MdFZbRE
b6fdRt76K+0FSl/CnyW9xaIlAhldXKbsgUDei3Xf/9P8H9Dxkk+PWd9Ha1RZ9Viz
dOLe2S2iDKc1CJg2kdGQTuQu6mUEGrB9WJmrLHJS7GkGDqy96owFjRL/p0i9KBdR
kgWG+GFHWkxzeNQ99yrQra3+C9FQXa/xLCdOY+BGOsAG7ej4094NZXRNTyXui4jR
WCm2GVdIVl7YB9++XSntS7zQEJ9QBnC1D4bS0tljMfdOGAvdUuJY7QIDAQABo1Aw
TjAdBgNVHQ4EFgQUJk4zcQ4JupEcAp0gEkob4YRDkckwHwYDVR0jBBgwFoAUJk4z
cQ4JupEcAp0gEkob4YRDkckwDAYDVR0TBAUwAwEB/zANBgkqhkiG9w0BAQUFAAOC
AQEAKvf9AO4+osJZOmkv6AVhNPm6JKoBSm9dr9NhwpSS5fpro6PrIjDZDLh/L5d/
+CQTDzuVsw3xwDtlm89lrzbqw5rSa2+ghJk79ijysSC0zOcD6ka9c17zauCNmFx9
lj9iddUw3aYHQcQRktWL8pvI2WCY6lTU+ouNM+owStya7umZ9rBdjg/fQerzaQxF
T0yV3tYEonL3hXMzSqZxWirwsyZ0TnhWJsgEnqqG9tCFAcFu2p+glwXn1WL2GCRv
BfuJMPzg7ZB419AEoeYnLktqAWiU+ISnVfbwFOJ+OM/O7VQOeHDm2AeYcwo12CAc
4GC9KWTs3QtS3GREPKYDlHRNxQ==
          ',
    ],
  ],
  'scope' => [
    0 => 'stanford.edu',
  ],
  'UIInfo' => [
    'DisplayName' => [
      'en' => 'Stanford University WebAuth',
    ],
    'Description' => [
    ],
    'InformationURL' => [
      'en' => 'http://shibboleth.stanford.edu/',
    ],
    'PrivacyStatementURL' => [
    ],
    'Logo' => [
      0 => [
        'url' => 'https://idp.stanford.edu/logo.png',
        'height' => 60,
        'width' => 80,
        'lang' => 'en',
      ],
    ],
  ],
  'name' => [
    'en' => 'Stanford University WebAuth',
  ],
];

$metadata['https://idp-uat.stanford.edu/'] = [
  'entityid' => 'https://idp-uat.stanford.edu/',
  'contacts' => [
    0 => [
      'contactType' => 'technical',
      'givenName' => 'Shibboleth Team',
      'emailAddress' => [
        0 => 'shibboleth-team@lists.stanford.edu',
      ],
    ],
  ],
  'metadata-set' => 'shib13-idp-remote',
  'expire' => 1561506930,
  'SingleSignOnService' => [
    0 => [
      'Binding' => 'urn:mace:shibboleth:1.0:profiles:AuthnRequest',
      'Location' => 'https://login-uat.stanford.edu/idp/profile/Shibboleth/SSO',
    ],
    1 => [
      'Binding' => 'urn:oasis:names:tc:SAML:2.0:bindings:HTTP-POST',
      'Location' => 'https://login-uat.stanford.edu/idp/profile/SAML2/POST/SSO',
    ],
    2 => [
      'Binding' => 'urn:oasis:names:tc:SAML:2.0:bindings:HTTP-POST-SimpleSign',
      'Location' => 'https://login-uat.stanford.edu/idp/profile/SAML2/POST-SimpleSign/SSO',
    ],
    3 => [
      'Binding' => 'urn:oasis:names:tc:SAML:2.0:bindings:HTTP-Redirect',
      'Location' => 'https://login-uat.stanford.edu/idp/profile/SAML2/Redirect/SSO',
    ],
  ],
  'ArtifactResolutionService' => [],
  'keys' => [
    0 => [
      'encryption' => TRUE,
      'signing' => TRUE,
      'type' => 'X509Certificate',
      'X509Certificate' => 'MIIDzDCCArQCCQCdJebZPEsQBzANBgkqhkiG9w0BAQsFADCBpzELMAkGA1UEBhMC
          VVMxEzARBgNVBAgMCkNhbGlmb3JuaWExETAPBgNVBAcMCFN0YW5mb3JkMRwwGgYD
          VQQKDBNTdGFuZm9yZCBVbml2ZXJzaXR5MTMwMQYDVQQLDCpBdXRoZW50aWNhdGlv
          biBhbmQgQ29sbGFib3JhdGlvbiBTb2x1dGlvbnMxHTAbBgNVBAMMFGlkcC11YXQu
          c3RhbmZvcmQuZWR1MB4XDTE2MDUyMzIwMTIxMVoXDTI2MDUyMTIwMTIxMVowgacx
          CzAJBgNVBAYTAlVTMRMwEQYDVQQIDApDYWxpZm9ybmlhMREwDwYDVQQHDAhTdGFu
          Zm9yZDEcMBoGA1UECgwTU3RhbmZvcmQgVW5pdmVyc2l0eTEzMDEGA1UECwwqQXV0
          aGVudGljYXRpb24gYW5kIENvbGxhYm9yYXRpb24gU29sdXRpb25zMR0wGwYDVQQD
          DBRpZHAtdWF0LnN0YW5mb3JkLmVkdTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCC
          AQoCggEBAJlkwhaVvmjhW6EGIATvco0UQntR1p9+XneAU7z08j3CLyjgb5n7qTgn
          3piZmENA0y3aD9cvIZ6ixYN8oCGfPTjwMr488cCQsBkvXCoA4O1XThvPsdd5KjQX
          y8IAsno6qrYsfeS+nlMgeJhHVPRRFkos+JUs0LGYHK/vZdMpIVYhDbH3udwjMP9O
          Qf4h1HCr4zy2n/XWg3GO9AyKq50ibTogOZy0wQr7gp1+l5RW0hXG1IYShbu57MaI
          TtsUZUMUJZGGGeEBYANWelJ8TnXvOJt0ZqLeULJSgCS8EyKQM4Ty5Qy7cbTVN8zP
          aPne4smCvpeAHxyaCqx3z6XXBgKutDcCAwEAATANBgkqhkiG9w0BAQsFAAOCAQEA
          DxXtRxiUAd9brr55fv0gxMFNTE7ayZh5BWFgukOvMyS0H1ces7NmiqoDJR3uMc7P
          1zdudiAoO4tlRGnMm9FA5eE8Rhm8WEPvwdaGcoiIu80yPXPHWx+7sBy4mAc4llrO
          AYwCbXM0E6jLh4Y068j+mLmzYzkW6Ro7mImTyGNYNWJUr3jP+79m6Fr0QbC44Giz
          S4UszE26axYpmhs2ONQFsOBs1VazgNt/LJfgQXK3MpdRct2vOMIeHSJAw6lJ1rfc
          CoS3z3uvz7LPaJdw4ZyDC9i0bQoKvfpi96pOnsc2TE/MMo3JbG2vW8g0G3f9xv5O
          PzwNr2FQZzZfjH0wg9dMfQ==',
    ],
  ],
  'scope' => [
    0 => 'stanford.edu',
  ],
  'UIInfo' => [
    'DisplayName' => [
      'en' => 'Stanford University Login (UAT)',
    ],
    'Description' => [],
    'InformationURL' => [
      'en' => 'http://saml.stanford.edu/',
    ],
    'PrivacyStatementURL' => [],
    'Logo' => [
      0 => [
        'url' => 'https://login-uat.stanford.edu/logo.png',
        'height' => 60,
        'width' => 80,
        'lang' => 'en',
      ],
    ],
  ],
  'name' => [
    'en' => 'Stanford University Login (UAT)',
  ],
];
